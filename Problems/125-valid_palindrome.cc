#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    vector<char> processed;
    for (auto c : s) {
      if (c >= 'A' && c <= 'Z') {
        processed.push_back(c - 'A' + 'a');
      } else if (c >= 'a' && c <= 'z') {
        processed.push_back(c);
      } else if (c >= '0' && c <= '9') {
        processed.push_back(c);
      }
    }
    int i = 0, j = processed.size() - 1;
    while (i < j) {
      if (processed[i] != processed[j]) return false;
      i++;
      j--;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
  std::cout << s.isPalindrome("race a car") << std::endl;
  std::cout << s.isPalindrome(" ") << std::endl;
  std::cout << s.isPalindrome("0P") << std::endl;
  return 0;
}