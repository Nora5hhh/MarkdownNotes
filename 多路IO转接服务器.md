# 多路I/O转接服务器

### 定义

多线程与多进程服务器需要**服务器程序去监听**访问请求，降低了程序执行效率且消耗CPU。因此大型应用采用多路IO转接服务器，也称多任务IO服务器。该类服务器不再由应用程序去监听客户端连接，**由内核**替代应用程序（服务器程序）去**监视文件**。

有客户端请求时内核会向服务器程序反馈，内核完成与该客户端的连接建立，当该客户端有事件如发送数据时，内核通知服务器，服务器无需阻塞就可以对该客户端发送的数据进行处理。

### 使用方法

#### select

1. 它能监听的文件描述符个数受限于FD_SETSIZE，一般为1024，单纯改变进程打开的文件描述符不改变select监听文件个数。
2. 由于select采用轮询模型，当连接客户端过多（大于1024）时，会很大降低服务器响应效率。
3. 位于sys/select.h头文件中![](C:\Users\86132\AppData\Roaming\Typora\typora-user-images\1583138379772.png)参数1表示所监听的文件描述符中，**最大的文件描述符+1**，参2表示所监听的文件描述符**“可读”**事件；参3表示**“可写”**事件；参4表示**“异常”**事件。返回值是所监听的**所有监听集合**（包括读、写、异常）中**满足条件的总数**。失败返回-1设置errno
4. 相关的4个函数FD_ZERO（将set清空为0，set是位图）、FD_CLR（将fd从set中清除）、FD_ISSET（判断fd是否在集合中）、FD_SET（将fd设置到set集合中去）
5. 缺点在于文件描述符个数有上限（1024），返回的只是一个数，只能轮询查找满足的文件描述符。因此一般**自定义数据结构**如数组去遍历。由于**监听集合与返回集合**是**同一个**，因此需要保存原有集合。



#### Poll

1. 位于poll.h头文件中![1583146879520](C:\Users\86132\AppData\Roaming\Typora\typora-user-images\1583146879520.png)struct pollfd是一个结构体，fds代表结构体数组的首地址，nfds表示数组中元素个数。
2. poll与select思想类似，都是帮助服务器在内核监听客户端请求。但是poll更好，poll可以**突破**1024个文件描述符（使用cat /proc/sys/fs/file-max命令查看一个进程可以打开的socket描述符上限）；且poll**监听与返回集合分离**；搜索范围更小，限于自定义的数组里。
3. poll的缺点在于，还是轮询遍历。



#### epoll

##### 定义

它是Linux下多路复用IO接口select/poll的增强版本，能显著的提高程序**在大量并发连接中只有少量活跃的情况下系统的CPU利用率**。

##### 基础API

1. 创建一个epoll句柄，参数size告知内核**监听的文件描述符个数**，与内存大小有关。`int epoll_create(int size);`在头文件sys/epoll.h中。返回文件描述符epfd，epfd是内核中**平衡二叉树（红黑树）**的根节点。
2. 控制某个epoll监控的文件描述符上的事件：注册、修改、删除。`int epoll_ctl(int epfd,int op,int fd,struct epoll_event *event)`，其中epfd是epoll_create的句柄，op表示动作，fd表示当前修改的文件描述符，event告知内核需要监听的事件。
3. **等待**所监控文件描述符上有事件的发生。`int epoll_wait(int epfd,struct epoll event* events,int maxevents,int timeout)`，成功返回就绪的文件描述符个数。

##### 调用流程

- `epoll_create();` ---`int epfd=epoll(size)`，表示这棵红黑树最多能监听size个节点，称epfd为句柄。
- `epoll_ctl();` ---`op:EPOLL_CTL_ADD/MOD/DEL`分别对应添加、修改、删除。
- `epoll_wait()`

