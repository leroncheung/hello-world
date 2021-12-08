#include <iostream>

using namespace std;

class Base {
public:
	virtual void func(int n = 10) {
		cout << n << "  Base()" << endl;
	}
};

class Derived : public Base {
public:
	virtual void func(int n = 20) {
		cout << n << "  Derived()" << endl;
	}
};


int main() {
	Derived *d = new Derived();
	Base *b = d;
	d->func();
	b->func();
	
	return 0;
}
