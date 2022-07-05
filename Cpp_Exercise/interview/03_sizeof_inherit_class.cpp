/**
 * @file 03_sizeof_inherit_class.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

using namespace std;

class A {
private:
    char k[8];

public:
    // void Getk() {}
    virtual void Getk();
};

class B : public A {
// class B : public virutal A {
public:
    char k[7];
    // void Getj(){}
    virtual void Getj() {}
};

class C : public B {
// class C : public virtual B {
public:
    char k[1];
    virtual void Geti() {}
};

int main() {
    cout << "sizeof(A) : " << sizeof(A) << endl;
    cout << "sizeof(B) : " << sizeof(B) << endl;
    cout << "sizeof(C) : " << sizeof(C) << endl;

    return 0;
}

// 总结
// 1. 普通继承时
// 计算类的大小时，需要考虑到字节对齐。派生类的成员填充字节会与基类的成员填充字节一起考虑：比如基类的char[3]和派生类的char[5]会放在一起，占用8个字节。
// 派生类包含基类的成员大小（无论是私有还是共有保护），也就是派生类的大小=基类的成员大小+派生类自己的成员大小，派生类与基类共用一个虚表指针。
// 2. 虚继承时
// 虚继承比较特殊：自带一个虚表指针，与本类是否包含虚函数无关。无论是否有虚函数在类中均只包含该一个指针。
//              并且，虚继承的派生类与基类的成员是互相隔离的，不会因为字节对齐填充在一起。
//