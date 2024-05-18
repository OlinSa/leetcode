
#include <string.h>

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int val = 0;
        bool is_native = true;

        // skip ' ' for begin
        while (s[i] == ' ')i++;
        if (s[i] == '-') is_native = false;
        if (s[i] == '+' || s[i] == '-') i++;

        //convert string to int
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (val > (INT32_MAX - digit) / 10) {
                return is_native ? INT32_MAX : INT32_MIN;
            }
            val = val * 10 + digit;
            i++;
        }
        return is_native ? val : -val;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.myAtoi("42") << std::endl;
    std::cout << s.myAtoi("-042") << std::endl;
    return 0;
}