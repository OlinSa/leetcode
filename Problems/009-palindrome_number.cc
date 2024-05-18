
#include <string.h>

#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::vector<int> vec;
        while (x > 0) {
            vec.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
            if (vec[i] != vec[j]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.isPalindrome(121) << std::endl;
    std::cout << s.isPalindrome(-121) << std::endl;
    std::cout << s.isPalindrome(10) << std::endl;
    return 0;
}