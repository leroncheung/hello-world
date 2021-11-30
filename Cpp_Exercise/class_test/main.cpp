// #include "A.h"
// #include "B.h"

#include "Derived.h"

int main() {
    // B *pb = new B();
    // A a(pb);
    // a.Show();
    // A a;
    // a.Show();
    // 针对两个类互相包含的情况，至少有一方的.h文件使用了前置声明，或者两方都使用前置声明才可以编译成功。
    // A类或B类的.cpp实现文件中，需要根据实际是否用到了对方的内置成员再去确定是否需要include该头文件。
    // 结论：前置声明只能作为指针或引用，不能定义类的对象，自然也就不能调用对象中的方法了。

    Derived d;
    d.Show();
    return 0;
}