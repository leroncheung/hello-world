#include <iostream>

std::shared_ptr<int> init_ptr;
std::once_flag init_flag;

void init() {
    std::cout << "Init..." << std::endl;
    init_ptr = std::make_shared<int>(12);
}

void func() {
    std::call_once(init_flag, init);
    std::cout << "func: " << *init_ptr << std::endl;
}

int main() {
    std::call_once(init_flag, init);
    func();
    std::cout << *init_ptr << std::endl;

    return 0;
}