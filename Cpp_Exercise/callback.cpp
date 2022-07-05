#include <iostream>
struct Foo {
    int value;
    void f() { std::cout << "f(" << this->value << ")\n"; }
    void g() { std::cout << "g(" << this->value << ")\n"; }
};
// using FunType = void (*)();
// typedef void(*FunType)();
void apply(Foo *foo1, Foo *foo2, void (Foo::*fun)())
{
    (foo1->*fun)();  // call fun on the object foo1
    (foo2->*fun)();  // call fun on the object foo2
    // fun();
}
int main() {
    Foo foo1{1};
    Foo foo2{2};
    apply(&foo1, &foo2, &Foo::f);
    apply(&foo1, &foo2, &Foo::g);
    // apply(&foo1, &foo2, Foo::f);
}