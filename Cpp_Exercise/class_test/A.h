#ifndef _A_H_
#define _A_H_

// #include "B.h"

class B;

class A {
public:
    B *pb;
    // A() = default;
    // A(B *b);
    void Show();
};

#endif