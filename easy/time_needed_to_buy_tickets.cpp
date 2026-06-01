#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        // sum(min(前面元素 val, 当前元素 val), min(前面元素 val - 1, 当前元素 val))
        std::queue<int> queue;
        for (int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        int time = 0;
        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();
            time++;
            tickets[front]--;

            if (front == k && tickets[front] == 0) {
                return time;
            }

            if (tickets[front] == 0) {
                continue;
            }

            queue.push(front);
        }
        return time;
    }
};

int main() {
    Solution sol;
    std::vector<int> tickets = {2, 3, 2};
    int k = 2;
    std::cout << "Time required: " << sol.timeRequiredToBuy(tickets, k) << std::endl;
    return 0;
}
