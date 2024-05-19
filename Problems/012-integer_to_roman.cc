#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        while (num > 0) {
            auto it = roman_map_.begin();
            while (it != roman_map_.end()) {
                if (num >= it->first) {
                    num -= it->first;
                    s += it->second;
                } else {
                    it++;
                }
            }
        }
        return s;
    }

private:
    std::vector<std::pair<int, std::string>> roman_map_ = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"},
    };
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.intToRoman(3749) << std::endl;
    std::cout << s.intToRoman(58) << std::endl;
    std::cout << s.intToRoman(1994) << std::endl;
    return 0;
}