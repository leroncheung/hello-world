#include <iostream>
#include <thread>
#include <chrono>

class background_task {
public:
    void do_something() const {
        std::cout << "hello ";
    }
    void do_something_else() const {
        std::cout << "concurrency!" << std::endl;
    }
    void operator()() const {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << "Process id: " << std::this_thread::get_id() << std::endl;
        do_something();
        do_something_else();
    }
};

int main() {
    background_task f;
    // std::thread t(f);
    std::thread t{background_task()};
    std::cout << "Hardware concurrency: " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "Process id: " << t.get_id() << std::endl;
    t.join();
    std::cout << "Process id: " << std::this_thread::get_id() << std::endl;
    
    return 0;
}