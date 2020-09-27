#### sizeof和strlen的区别

sizeof是运算符，它的功能是获得保证能容纳实现所建立的最大对象的字节大小。

strlen返回字符串的长度。

strlen("world")=5 sizeof("world")=6

#### const与vector

参考链接：https://www.cnblogs.com/XiaoXiaoShuai-/p/10750560.html

一般选用const vector<int> a这种，表示a既不能修改，也不能增加。只能访问。