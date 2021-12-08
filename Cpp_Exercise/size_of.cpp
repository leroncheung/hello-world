#include <iostream>

using namespace std;

class Base {
public:
	static int m_a;
	int m_b;
	char m_c;
	virtual void printA() {
	}
	virtual void printB() {
	}
};

class Derived : public Base {
public:
	void printA() {
	}
	void printB() {
	}
};

int main() {
	cout << sizeof(Base) << "  " << sizeof(Derived) << endl;
	Base a;
	Derived b;
	cout << sizeof(a) << "  " << sizeof(b) << endl;
	
	return 0;
}
