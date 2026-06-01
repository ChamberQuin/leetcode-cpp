#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return std::vector<int>{i, j};
                }
            }
        }
        return std::vector<int>{};
    }

    std::vector<int> twoSum2(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {i, map[complement]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = sol.twoSum2(nums, target);
    std::cout << "Result: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
