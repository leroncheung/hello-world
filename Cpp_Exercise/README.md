# Cpp exercise index
- C++练习索引
- **注意**：代码不完全正确，只为做验证和练习使用


# Indexes
## ./class/A.h, B.h
- 两个类互相包含时，至少有一方的头文件包含另一个类的前置声明，此时另一方使用include头文件；或者两个都使用前置声明（cpp文件中用到类的函数的话仍然需要include）
- class A;
- class B;

## ./string_h_realize/my_string_h.cpp
- memcpy, memmove, strcpy, strncpy, strlen
- 注意内存重叠
- `if (pSrc < pDest && pSrc + n > pDest)`


## abstract_func.cpp
- 虚函数。若派生类没有实现基类的虚函数，则基类指针即便指向派生类对象，也无法使用多态（派生类没有该虚函数）


## Big_endian.cpp
- 大端模式和小端模式的识别，X86，ARM平台多用小端模式。int强制转换为char，判断高位字节是否保存在低地址中。
- `char b = *(char *)&a;`


## callback.cpp
- 利用函数指针可以作为函数参数实现函数回调
- `void (*func_ptr)(int, int);`
- `void (A::*mem_func_ptr)(int, int)`


## circular_reference.cpp
- 使用weak_ptr解决两个类循环引用的问题，只需将其中一个shared_ptr改为weak_ptr即可。


## cons_des_of_static_local_var.cpp
- 静态全局变量/静态局部变量的构造函数和析构函数的调用顺序
-- 静态全局变量与全局变量都是在main函数前的编译阶段就构造好了
-- 静态局部变量是在程序执行到定义该静态局部变量的时候才开始构造，参考单例模式中的magic static（懒汉模式）


## constructor_destructor.cpp
- 构造函数和析构函数是一对
- 如果在构造函数中new了新的对象，注意要在析构函数（或者提供其他Delete函数）中调用delete该对象，防止内存泄漏


## copy_and_move_constructor.cpp
- 拷贝构造函数，拷贝赋值运算符，移动构造函数和移动赋值运算符的调用
-- 创建新对象就调用拷贝构造函数： `A a = A(10);`
-- 赋值给一个现有对象就调用拷贝赋值运算符：`b = a;`
-- 移动构造函数和移动赋值运算符需要看具体的编译器


## DeepCopy.cpp
- 深拷贝
-- 构造函数：新创建对象，直接new，然后copy
-- 拷贝构造函数：新创建对象，直接new，然后copy
-- 拷贝赋值运算符：判断对象是否是自身，赋值前需delete原有对象占用的内存。再通过new申请新内存，然后copy


## explicit.cpp
- 单参数构造函数为了避免隐式转换，加explicit关键字
-- `A a = 10; // 隐式转换，加了explicit后不允许这种定义，只能用构造函数`
-- `A a = A(10)  //转换成了这种形式`


## for_each.cpp
- for_each很适合与lambda表达式配合


## function_callback.cpp
- 使用<functional>中的std::function实现函数回调
- std::function 实现函数指针的作用，需要于bind函数配合使用才能完成std::function函数参数传递


## function_ptr.cpp
- 函数指针
-- 普通函数的指针定义：`void (*func1_ptr)(int, int)`
--- `func1_ptr = Add;`
--- `func1_ptr(a, b);`
-- 类成员函数的指针定义：`void (A::*func2_ptr)()`
--- `func2_ptr = A::func2;`
--- `(a.*func2_ptr)();`


## IOStream_override.cpp
流输入输出操作符的重载
- `istream &operator>>(istream &is, Student &a);`
- `ostream &operator<<(ostream &os, Student &a;`


## Operator_override.cpp
运算符重载（成员函数或全局友元函数），实现自定义类型的+，-，*，/等操作
- `Complex &Complex::operator+(const Complex& tmp);`
- `Complex &operator-(const Complex& a, const Complex& b);`


## size_of.cpp
- 空类大小为1字节，占位字节
- 类的大小与成员函数和静态成员没有关系，只与普通成员变量和虚函数（存在虚函数就多一个虚表指针，64位下为8字节）有关


## smart_ptr.cpp
- 以shared_ptr为原型实现的智能指针类模板
-- 构造函数和析构函数
-- 拷贝构造函数和拷贝赋值运算符
-- 运算符*和运算符->的重载


## static_dynamic_bind.cpp
- 静态绑定：编译期间确认，包括默认函数参数
- 动态绑定：运行期间确定，虚函数实现
