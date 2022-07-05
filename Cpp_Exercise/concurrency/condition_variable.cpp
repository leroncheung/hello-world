#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>

class data_chunk {
};
bool more_data_to_prepare() {
    return true;
}
data_chunk prepare_data() {
    return data_chunk();
}
void process(data_chunk data) {}
bool is_last_chunk(data_chunk data) {
    return true;
}

std::mutex mut;
std::queue<data_chunk> data_queue;
std::condition_variable data_cond;

void data_preparation_thread() {
    while(more_data_to_prepare) {
        data_chunk const data = prepare_data();
        {
            std::lock_guard<std::mutex> lock(mut);
            data_queue.push(data);
        }
        data_cond.notify_one();
    }
}

void data_processing_thread() {
    while(true) {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, []
                       { return !data_queue.empty(); });
        data_chunk data = data_queue.front();
        data_queue.pop();
        lock.unlock();
        process(data);
        if (is_last_chunk(data)) {
            break;
        }
    }
}