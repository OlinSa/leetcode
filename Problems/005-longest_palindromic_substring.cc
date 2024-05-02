#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    //      i   j
    // s = "a b a a b a d" ==> baab
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int l_bound = 0, r_bound = 0; // l_bound及r_bound分别为最大回文数的左右边界
        // 这里以每个点都标记为原点, 向两边发散
        for (int i = 0; i < n; i++) {
            int len = 1;
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && s[l] == s[i]) { //查找左边界
                len++;
                l--;
            }
            while (r < n && s[r] == s[i]) { //查找右边界
                len++;
                r++;
            }

            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                len += 2;
            }
            if (len > (r_bound - l_bound + 1)) {
                l_bound = l + 1;
                r_bound = l + len;
            }
        }
//        std::cout << "l_bound:" << l_bound << ",r_bound:" << r_bound <<
//                  std::endl;
        return s.substr(l_bound, r_bound - l_bound + 1);
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    std::cout << solution.longestPalindrome("babad") << std::endl;
    std::cout << solution.longestPalindrome("cbbd") << std::endl;
    std::cout << solution.longestPalindrome("ab") << std::endl;
    std::cout << solution.longestPalindrome("bb") << std::endl;
    std::cout << solution.longestPalindrome("aacabdkacaa") << std::endl;
    return 0;
}