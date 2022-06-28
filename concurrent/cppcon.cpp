#include <iostream>
#include <thread>
#include <string>

using namespace std;

void hello()
{
    cout << "hello cpp!" << endl;
}


void func(int i, string const&s) {
    cout << i << " " << s << endl;
}
void oppos(int some_param) {
    char buff[1024];
    sprintf(buff, "%i", some_param);
    thread t(func, 3, buff);
    t.detach();
}

void none_oppos(int some_param) {
    char buff[1024];
    sprintf(buff, "%i", some_param);
    thread t(func, some_param, string(buff));
    t.detach();
}

int main()
{
    // thread t(hello);
    // t.join();
    // oppos(1);
    none_oppos(2);

    return 0;
}