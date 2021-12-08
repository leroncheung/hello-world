#include <iostream>

using namespace std;

class A {
public:
	A() : ptr(this) {
	}
	~A() {
		cout << "Destructor()" << endl;
//		if (ptr != nullptr) {
//			cout << "des" << endl;
//			delete ptr;
//			ptr = nullptr;
//		}
	}

private:
	A *ptr;
};

int main() {
	A *a = new A();
	delete a;
	
	return 0;
}
