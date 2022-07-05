#include <iostream>
#include <mutex>
#include <list>

void InsertNode(std::list<int>::iterator it, std::list<int>& list1, int val) {
    std::mutex mutex;
    // mutex.lock();
    std::lock_guard<std::mutex> guard(mutex);
    std::unique_lock<std::mutex> lk(mutex);
    lk.unlock();
    list1.emplace_back(val);
    // mutex.unlock();
}

int main() {
    std::list<int> list1;
    InsertNode(list1.begin(), list1, 12);
    for (auto it = list1.begin(); it != list1.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::lock();
    return 0;
}