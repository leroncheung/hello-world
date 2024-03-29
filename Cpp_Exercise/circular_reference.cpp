#include <iostream>
#include <memory>

using namespace std;

class B;

class A {
public:
	weak_ptr<B> pB;
	// shared_ptr<B> pB;
	
	A() {
		cout << "A::A()" << endl;
	}
	~A() {
		cout << "A::~A()" << endl;
	}
};

class B {
public:
	shared_ptr<A> pA;
	
	B() {
		cout << "B::B()" << endl;
	}
	
	~B() {
		cout << "B::~B()" << endl;
	}
};

int main() {
	shared_ptr<B> pb = make_shared<B>();
	shared_ptr<A> pa = make_shared<A>();
	pb->pA = pa;
	pa->pB = pb;
	
	return 0;
}
