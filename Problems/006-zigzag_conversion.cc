#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

//   A B C D E F G

//   rows = 3 时 
//   A     E
//   B  D  F
//   C     G

//   rows = 4 时
//            j
// i  A       G
//    B     F
//    C  E
//    D

    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() < numRows) return s;
        // 构建array, arr[numRows][s.size()]
        int r = numRows;
        int t = r * 2 - 2; // T为一个周期
        int x = 0, y = 0;
        std::vector<std::string> arr(r, std::string(s.length(), 0));
        for (int i = 0; i < s.length(); ++i) {
            arr[x][y] = s[i];
            if (i % t < r - 1) {// to down
                ++x;
            } else { // to upper right
                --x;
                ++y;
            }

        }
        std::string zigzap;
        for (auto str: arr) {
            for (char c: str) {
                if (c) {
                    zigzap += c;
                }
            }
        }
        return zigzap;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.convert("ABCDEFG", 3);
    return 0;
}