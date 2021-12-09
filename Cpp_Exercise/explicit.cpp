#include <iostream>

using namespace std;

class A {
public:
	int ma;
	explicit A(int tmp) {
		cout << "A::A()" << endl;
		ma = tmp;
	}
	A (const A& tmp) {
		cout << "A::A(const A&)" << endl;
		ma = tmp.ma;
	}
	A& operator = (const A& tmp) {
		cout << "A::operator = ()" << endl;
		ma = tmp.ma; 
	}
};

int main() {
	A a = A(10);
	A b(10);
	A c = a;
	c = b;
    
    return 0;
}

