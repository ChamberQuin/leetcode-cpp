#pragma once

#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <unordered_map>
template<typename Key, typename Value>
class SingleFlight {
public:
template<typename Func>
Value call(const Key& key, Func&& func) {
    std::unique_lock<std::mutex> lock(mutex_);
    auto it = calls_.find(key);
    if (it != calls_.end()) {
        // already has inflight call
        auto future = it->second;
        lock.unlock();
        return future->get_future().get();
    }

    // first call
    auto promise = std::make_shared<std::promise<Value>>();
    calls_[key] = promise;
    lock.unlock();

    try {
        Value result = func();
        promise->set_value(result);
    } catch (...) {
        promise->set_exception(std::current_exception());
    }

    // cleanup
    lock.lock();
    calls_.erase(key);
    return promise->get_future().get();
}

private:
    std::mutex mutex_;
    std::unordered_map<Key, std::shared_ptr<std::promise<Value>>> calls_;
};

int main() {
    SingleFlight<std::string, std::string> sf;

    auto result1 = sf.call("key1", []() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return "called";
    });
    auto result2 = sf.call("key1", []() {
        return "not called";
    });
    
    std::cout << result1 << " " << result2 << std::endl;
    return 0;
}