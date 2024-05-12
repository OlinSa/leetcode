#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x != 0) {
            if (ret < INT_MIN / 10 || ret > INT_MAX / 10) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.reverse(1234) << std::endl;
    std::cout << s.reverse(-1234) << std::endl;
    std::cout << s.reverse(1534236469) << std::endl;

    return 0;
}