#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    string prefex = strs[0];

    for (int i = 1; i < strs.size(); i++) {
      prefex = longestCommonPrefix(prefex, strs[i]);
    }

    return prefex;
  }
  string longestCommonPrefix(string& str1, string& str2) {
    auto it1 = str1.begin();
    auto it2 = str2.begin();

    while (it1 != str1.end() && it2 != str2.end()) {
      if (*it1 != *it2) {
        break;
      }
      it1++;
      it2++;
    }
    return it1 != str1.begin() ? string(str1.begin(), it1) : "";
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<string> strs1 = {"flower", "flow", "flight"};
  vector<string> strs2 = {"dog", "racecar", "car"};
  std::cout << s.longestCommonPrefix(strs1) << std::endl;
  std::cout << s.longestCommonPrefix(strs2) << std::endl;

  return 0;
}