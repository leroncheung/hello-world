#include <iostream>

using namespace std;

class Base {
public:
	Base() {};
	virtual ~Base() = default;
	virtual void func();
};

void Base::func() {
	cout << "Base::func()" << endl;
}

class Derived : public Base {
public:
	Derived() {
//		Base();
		cout << "Derived::Derived()" << endl;
	}
	~Derived() = default;
	void func();
};

void Derived::func() {
	cout << "Derived::func() " << endl;
}

int main() {
	Base *p = new Derived();
//	p->func();
	
	return 0;
}
