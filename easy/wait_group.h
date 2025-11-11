#pragma once

#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
class WaitGroup {
public:
    void add(int delta = 1) {
        std::unique_lock<std::mutex> lock(mutex_);
        counter_ += delta;
        if (counter_ <= 0) {
            cv_.notify_all();
        }
    }

    void done() {
        add(-1);
    }

    void wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]() { return counter_ <= 0; });
    }

private:
    int counter_ = 0;
    std::mutex mutex_;
    std::condition_variable cv_;
};

int main() {
    WaitGroup wg;
    
    for(int i = 0; i < 10; i++) {
        wg.add();
        std::thread([&wg]() {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            wg.done();
        }).detach();
    }

    wg.wait();
    std::cout << "all tasks done" << std::endl;
    return 0;
}