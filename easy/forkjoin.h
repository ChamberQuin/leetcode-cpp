#pragma once

#include <future>
#include <iostream>
#include <vector>
class ForkJoin {
public:

template<typename T, typename Func>
std::vector<T> fork_join(const std::vector<T>& input, Func&& func) {
    std::vector<std::future<T>> futures;

    // fork: start multiple async tasks
    for (const auto& task : input) {
        futures.emplace_back(std::async(std::launch::async, func, task));
    }

    // join: wait for all tasks to complete and collect results
    std::vector<T> results;
    for (auto& future : futures) {
        results.push_back(future.get());
    }

    return results;
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    auto results = fork_join(input, [](int x) {
        return x * x;
    });

    for (const auto& result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}

};