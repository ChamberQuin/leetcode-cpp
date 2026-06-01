#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> left;
        for (char c : s) {
            if ( c == '(' || c == '[' || c == '{') {
                left.push(c);
            } else {
                if (left.empty() || left.top() != leftOf(c)) {
                    return false;
                }
                left.pop();
            }
        }
        return left.empty();
    }

    char leftOf(char c) {
        if (c == '}') return '{';
        if (c == ']') return '[';
        return '(';
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::cout << "Test 1: " << sol.isValid("()") << std::endl;
    std::cout << "Test 2: " << sol.isValid("()[]{}") << std::endl;
    std::cout << "Test 3: " << sol.isValid("(]") << std::endl;
    return 0;
}
