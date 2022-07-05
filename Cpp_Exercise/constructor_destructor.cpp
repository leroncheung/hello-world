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
    p = new int[n];
    // p = T;
    for(int i=0; i<n; i++)
    {
        p[i]=i;
        V.push_back(&(p[i]));
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

// int main()
// {   
//     MyClass C(5);
    // MyClass *pp = new MyClass(10);
    // delete pp;
//     return 0;
// }

class A
{
public:
    A() {}
    ~A() { cout << "~A" << endl; }
};

class B : public A
{
public:
    B() {
        cout << "B::B()" << endl;
    }
    B(A &a) : _a(a)
    {
        cout << "B::B(A&)" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }

private:
    A _a;
};

int main(void)
{
    A a; //很简单，定义a的时候调用了一次构造函数
    // B b;
    B b(a);

    return 0;
}

// 总结：
// 1. 析构函数和默认构造函数类似，派生类在析构时同样会调用基类的析构函数； 
// 2. 类的成员变量，即便没有在构造函数（包括默认构造函数）中显示初始化，也会在构造函数调用前默认进行初始化。

// 派生类的析构函数没有被执行，仅限于多态场景下，基类的虚函数没有被声明为virtual时才会发生。非多态场景下，对析构函数是否是virtual函数没有要求。