1. tlinux1.2 版本 或centos 6 补丁
   
   需要手动修改2行代码
   https://github.com/google/protobuf/pull/2599/commits/141a1dac6ca572056c6a8b989e41f6ee213f8445

2. 编译步骤：

```
$ ./configure
$ make
$ make check
$ sudo make install
$ sudo echo "/usr/local/lib" >> /etc/ld.so.conf
$ sudo ldconfig # refresh shared library cache.
```

3. pb头文件和库文件安装路径
```
/usr/local/include/google/protobuf/
/usr/local/lib/
```

4. 协议文件demo
test.proto
```
syntax = "proto3";
message Test{
   string name = 1;
   int32  age  = 2;
}

```

5. 协议代码生成
```
protoc -I=./ --cpp_out=./ ./test.proto 
```

6. 测试代码编译
test.cpp 

```
#include<stdio.h>
#include"test.pb.h"
   
int main()
{
    Test *test = new Test();
    test->set_name("123");
    test->set_age(1234);
    printf("test !!!!");
    return  0;
}
```

```
g++ -o test test.cpp test.pb.cc -I /usr/local/include -L /usr/local/lib -lprotobu
```
