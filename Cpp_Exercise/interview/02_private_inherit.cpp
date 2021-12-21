/**
 * @file 02_private_inherit.cpp
 * @author leroncheung
 * @brief
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <stdio.h>
class Parent
{
public:
    int m_nPub;
    Parent(int var = -1)
    {
        m_nPub = var;
        m_nPtd = var;
        m_nPrt = var;
    }

protected:
    int m_nPtd;

private:
    int m_nPrt;
};

class Child1 : public Parent
{
public:
    int GetPub() { return m_nPub; };
    int GetPtd() { return m_nPtd; };
    // int GetPrt(){return m nPrt;};
    // A
};

class Child2 : protected Parent
{
public:
    int GetPub() { return m_nPub; }
    int GetPtd() { return m_nPtd; }
    // int GetPrt() { return m_nPrt; }
    // B
};

class Child3 : private Parent {
public:
    int GetPub() { return m_nPub; }
    int GetPtd() { return m_nPtd; }
    // int GetPrt() { return m_nPrt; }
    // C
};

int main() {
    Child1 cd1;
    Child2 cd2;
    Child3 cd3;
    int nVar = 0;

    // public inherited
    cd1.m_nPub = nVar;
    // D
    // cd1.m_nPtd = nVar;
    // E
    nVar = cd1.GetPtd();
    // F
    // protected inherited
    // cd2.m_nPub = nVar;
    // G
    nVar = cd2.GetPtd();
    // H
    // private inherited
    // cd3.m_nPub = nVar;
    // I
    nVar = cd3.GetPtd();
    // J
    
    return 0;
}

// 编译报错的行有：A，B，C，E，G，I