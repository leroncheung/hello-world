#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
    friend istream &operator>>(istream &is, Student &s);
    friend ostream &operator<<(ostream &os, Student &s);

public:
    Student() = default;
    ~Student() = default;
    Student(string id, string sex, string name) : id(id), sex(sex), name(name) {}

private:
    string id;
    string sex;
    string name;
};

istream &operator>>(istream &is, Student &s)
{
    string str;
    is >> str;
    auto pos1 = str.find(',', 0);
    auto id = str.substr(0, pos1);
    auto pos2 = str.find(',', pos1 + 1);    // "12,male,tom"
    auto sex = str.substr(pos1 + 1, pos2 - pos1 - 1);
    auto name = str.substr(pos2 + 1, str.size() - pos2);
    s.id = id;
    s.sex = sex;
    s.name = name;
    return is;
}

ostream &operator<<(ostream &os, Student &s)
{
    os << "Info: " << s.id << "," << s.sex << "," << s.name;
    return os;
}

int main() {
    ifstream cin("input.txt");
    Student s("12","male","Tom");
    cout << s << endl;
    cin >> s;
    cout << s << endl;

    return 0;
}