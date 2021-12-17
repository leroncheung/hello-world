#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
    MyString() : ss(new char[1])
    {
        ss[0] = 0;
    }
    ~MyString() {
        delete[] ss;    // 处理指针释放，注意不能定义为delete ss;
    }

    MyString(const char *s) {
        ss = new char[strlen(s) + 1];       // 构造函数新分配内存
        strcpy(ss, s);
    }
    MyString(const MyString &s)
    {
        ss = new char[strlen(s.ss) + 1];    // 构造函数新分配内存
        strcpy(ss, s.ss);
    }
    const char *c_str()
    {
        return ss;
    }

    MyString& operator=(const char* tmp) {
        delete[] ss;
        ss = new char[strlen(tmp) + 1];
        strcpy(ss, tmp);
        return *this;
    }

    MyString& operator=(const MyString& tmp) {
        if (this == &tmp) {
            return *this;
        }
        delete[] ss;
        ss = new char[strlen(tmp.ss) + 1];
        strcpy(ss, tmp.ss);
        return *this;
    }

private:
    char *ss;
};


int main() {
    MyString str1("hello");
    cout << str1.c_str() << endl;
    MyString str2 = str1;
    cout << str2.c_str() << endl;
    MyString str3(str2);
    cout << str3.c_str() << endl;
    MyString str4 = "world";
    cout << str4.c_str() << endl;

    return 0;
}