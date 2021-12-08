#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
    MyClass() = default;        
    MyClass(int n);
    ~MyClass();

private:
	vector<int*> V;
	int* p;
};

MyClass::MyClass(int n)
{
    int* T = new int[n];
    p = T;
    for(int i=0; i<n; i++)
    {
        T[i]=i;
        V.push_back(&(T[i]));
    }
}

MyClass::~MyClass()
{
	cout << "des" << endl;
	delete p;
//	if (!V.empty()) {
//		delete V[0];
//	}
//    for(int i =0; i<V.size(); i++)
//        delete V[i];
}

int main()
{   
    MyClass C(5);
    return 0;
}

