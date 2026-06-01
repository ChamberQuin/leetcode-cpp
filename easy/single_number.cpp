#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        for (int num: nums) {
            if (count[num] == 1) {
                return num;
            }
        }
        return -1;
    }

    int singleNumber2(std::vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4, 1, 2, 1, 2};
    std::cout << "singleNumber: " << sol.singleNumber(nums) << std::endl;
    std::cout << "singleNumber2: " << sol.singleNumber2(nums) << std::endl;
    return 0;
}
