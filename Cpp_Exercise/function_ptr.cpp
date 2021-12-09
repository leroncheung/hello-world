#include <iostream>

using namespace std;

class A {
public:
	void func() {
		cout << "func()" << endl;
	}
};

void Add(int a, int b) {
	cout << a + b << endl;
}

int main() {
	void (*func_p1)(int, int);
	func_p1 = &Add;
	func_p1(1, 2);
	
	void (A::*func_p2)();
	func_p2 = A::func;
	A a;
	(a.*func_p2)();
	
	return 0;
}
