# 第二章 空间配置器allocator

### 1、空间配置器的标准接口

- `allocator::allocator()`-default constructor默认构造
- `allocator::allocator(const allocator&)`-拷贝构造copy constructor
- `template <class U>allocator::allocator(const allocator<U>&)`-泛化的拷贝构造
- `allocator::~allocator()`-析构<img src="C:\Users\86132\AppData\Roaming\Typora\typora-user-images\1583730060460.png" style="width:250px"/>
- `pointer allocator::address(reference x) const`-返回对象的地址，`a.address(x)`等价于`&x`
- `void allocator::deallocate(T* p,size_t n)`-归还先前配置的空间

#### 1.1设计一个简单的空间配置器

在编写空间配置器时，需要将它们包含在`namespace XX{ }`这样的形式中，原因是它可以追加内容，为这个名空间定义许多东西。可以使用XX::M可以访问使用这个对象。<img src="C:\Users\86132\AppData\Roaming\Typora\typora-user-images\1583742501561.png" style="width:200px"/>

编写时会用到`set_new_handle(0)`，这句话主要是为了卸载目前的内存分配异常处理函数，一旦分配失败就会强制抛出`bad_alloc`异常。

#### 1.2 SCI特殊的空间配置器，`std::alloc`

定义`Foo`类后，通常所用的内存配置与释放操作是这样的<img src="C:\Users\86132\AppData\Roaming\Typora\typora-user-images\1583745347600.png" style="width:200px"/>

步骤为：

- 调用`operator new`**配置**内存
- 调用`Foo::Foo()`构造对象内容
- 调用`Foo:~Foo()`将对象析构
- 调用`::operator delete`释放内存

**内存配置**操作由`allocate()`负责，内存**释放**由`deallocate()`负责，对象**构造**由`construct()`负责，对象**析构**`destroy()`负责。

