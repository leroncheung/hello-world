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
	// 若派生类没有实现基类的虚函数，则基类指针即便指向派生类对象，也无法使用多态（派生类没有该虚函数）

		return 0;
}
