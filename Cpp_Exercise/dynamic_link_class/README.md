# 生成和链接静态和动态库
> Linux下使用clang++进行编译和链接，g++用法类似

1. 生成静态库和链接
```sh
# 生成 add.o
clang++ -std=c++11 -c add.cpp
# 打包生成静态库文件 libadd.a
ar -r libadd.a add.o
# 编译链接生成 main_static可执行文件
clang++ -std=c++11 main.cpp -L. -ladd -o main_static
# 运行
./main_static
```
2. 生成动态库和链接
```sh
# 生成动态库文件 libtest.so
clang++ -std=c++11 test.cpp -shared -fPIC -o libtest.so
# 编译链接生成可执行文件 main_dynamic
clang++ -std=c++11 main.cpp -L. -ltest -o main_dynamic
# 运行
./main_dynamic
```