/**
 * @file 04_Base_Derived_virtual.cpp
 * @author leroncheung
 * @brief 
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

class Base {
public:
    void func() {
        cout << "Base::func()" << endl;
    }
    virtual void ff() {
        cout << "Base::ff()" << endl;
    }
};

class Derived : public Base {
public:
    void func() {
        cout << "Derived::func()" << endl;
    }
};

int main() {
    // Base *p = new Derived();
    // p->func();

    // 父类对象转子类
    Base *b = new Derived();
    // Base *b = new Base();
    Derived *d = dynamic_cast<Derived *>(b);
    d->func();

    // 子类对象转父类
    Derived *d = new Derived();
    Base *b = static_cast<Base*>(d);
    b->func();

    return 0;
}

// 总结
// 想要使用dynamic_cast运行基类转派生类成功，要满足两点： 
// 1. 基类有虚函数；
// 2. 要转换的基类指针或引用本身就指向要转换的派生类类型的对象

// 1.虚函数：子类对象转父类【运行正常：执行子类的虚函数】 
// 2.虚函数：父类对象转子类【运行报错：段错误】或者【运行正常：执行子类的虚函数】 
// 3.虚函数：子类没有重写虚函数：子类对象转父类【运行正常：执行父类的虚函数】 
// 4.虚函数：子类没有重写虚函数：父类对象转子类【运行报错：段错误】或者【运行正常：执行父类的虚函数】
// 5.普通函数：子类对象转父类【运行正常：执行父类函数】 
// 6.普通函数：父类对象转子类【编译报错：提示父类非多态】 
// 7.普通函数：没有隐藏：子类对象转父类【运行正常：执行父类函数】 
// 8.普通函数：没有隐藏：父类对象转子类【编译报错：提示父类非多态】
