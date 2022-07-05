#ifndef _A_H_
#define _A_H_

#include "B.h"

// class B;    // 前置声明

class A {
public:
    B *pb;
    A() = default;
    A(B *b);
    void Show();
};

#endif