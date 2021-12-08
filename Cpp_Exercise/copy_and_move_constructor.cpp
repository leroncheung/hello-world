#include <iostream>

using namespace  std;
class Person
{
public:
    Person() {}
    Person( const Person& p )
    {
        cout << "Copy Constructor" << endl;
    }

    Person& operator=( const Person& p )
    {
        cout << "Copy Assign" << endl;
        return *this;
    }
    
    Person(const Person&& p) {
    	cout << "Move Constructor" << endl;
	}
	
	Person& operator= (const Person&& p) {
		cout << "Move Assign" << endl;
	}

private:
    int age;
    string name;
};

void f( Person p )
{
    return;
}

Person f1( )
{
    Person p;
    return p;
}


int main()
{
//    Person p;
//    Person p1 = p;		//  Copy constructor
    Person p2;			//
//    p2 = p;           	// 	assign
//    f(p2);            	// 	Copy
    p2 = f1();        	// 4
    Person p3 = f1(); 	// 5

    return 0;
}
