#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_string = 0;
        unordered_set<int> elem_sub_set;
        for(int i = 0; i < s.length(); ++i) {
            int k = i;
            while(k < s.length() && elem_sub_set.count(s[k]) == 0) {
                elem_sub_set.insert(s[k]);
                ++k;
            }
            max_string = std::max(max_string, k-i);
            elem_sub_set.clear();
        }
        return max_string;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    std::cout<<solution.lengthOfLongestSubstring("abcabcbb")<<std::endl;
    std::cout<<solution.lengthOfLongestSubstring("bbbbb")<<std::endl;
    std::cout<<solution.lengthOfLongestSubstring("pwwkew")<<std::endl;
    return 0;
}