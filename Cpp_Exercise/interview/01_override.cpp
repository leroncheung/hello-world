/**
 * @file 01_override.cpp
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

class A {
protected:
    int m_data;

public:
    A(int data =  0) : m_data(data) {}
    int GetData() {
        return doGetData();
    }
    virtual int doGetData() {
        return m_data;
    }
};

class B : public A {
protected:
    int m_data;

public:
    B(int data = 1) : m_data(data) {}
    int doGetData() {
        return m_data;
    }
};

class C : public B {
protected:
    int m_data;

public:
    C(int data = 2) : m_data(data) {}
};

int main() {
    C c(10);
    cout << c.GetData() << endl;
    cout << c.A::GetData() << endl;
    cout << c.B::GetData() << endl;
    cout << c.C::GetData() << endl;
    cout << c.doGetData() << endl;
    cout << c.A::doGetData() << endl;
    cout << c.B::doGetData() << endl;
    cout << c.C::doGetData() << endl;

    return 0;
}