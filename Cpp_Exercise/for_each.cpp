#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std::placeholders;
using namespace std;

ostream & print(ostream &os, const string& s, char c)
{
    os << s << c;
    return os;
}

int main()
{
    vector<string> words{"helo", "world", "this", "is", "C++11"};
    ostringstream os;
    char c = ' ';
    for_each(words.begin(), words.end(), [&os, c](const string & s){os << s << c;} );
    cout << os.str() << endl;

    ostringstream os1;
    // ostream���ܿ�������ϣ�����ݸ�bindһ������
    // �������������ͱ���ʹ�ñ�׼���ṩ��ref����
    for_each(words.begin(), words.end(), bind(print, ref(os1), _1, c));
    cout << os1.str() << endl;
}
