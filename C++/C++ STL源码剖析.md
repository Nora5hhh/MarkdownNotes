### 空间配置器(allocator)

allocator使用allocate->operator new->malloc分配空间，使用deallocate->operator delete->free释放空间。缺点在于它只是对operator new和delete做了一层封装，没有效率上的强化。常见的C++内存配置和释放操作如下：

<img src="C++ STL源码剖析.assets/image-20200914110943519.png" alt="image-20200914110943519" style="zoom:50%;" />

其中**new**包含两个阶段的操作：

- 调用operator new配置内存，由allocate负责
- 调用Foo()构造对象，由construct负责

**delete**包含两阶段操作：

- 调用~Foo()将对象析构，由destroy负责
- 调用operator delete释放内存，由deallocate负责



