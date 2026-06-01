#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (int num : nums) {
            if (set.count(num)) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::cout << std::boolalpha;
    std::cout << "Test 1: " << sol.containsDuplicate(nums1) << std::endl;
    std::cout << "Test 2: " << sol.containsDuplicate(nums2) << std::endl;
    return 0;
}
