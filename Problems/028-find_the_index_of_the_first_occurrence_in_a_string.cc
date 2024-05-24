#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();

    for (int i = 0; i <= m - n; ++i) {
      int l = i, k = 0;
      while (k < n && haystack[l] == needle[k]) {
        l++;
        k++;
      }
      if (k == n) return i;
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.strStr("sadbutsad", "sad") << std::endl;
  std::cout << s.strStr("leetcode", "leeto") << std::endl;
  std::cout << s.strStr("mississippi", "issip") << std::endl;
  return 0;
}