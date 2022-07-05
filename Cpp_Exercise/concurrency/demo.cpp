#include <iostream>
#include <thread>

void hello() {
    std::cout << "hello concurrency!" << std::endl;
}

int main() {
    std::thread t(hello);
    t.join();

    return 0;
}