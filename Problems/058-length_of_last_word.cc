#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int n = s.size();
    int i = n - 1;
    while (s[i] == ' ' && i >= 0) {
      i--;
    }
    int length = 0;
    while (i >= 0 && s[i] != ' ') {
      i--;
      length++;
    }
    return length;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.lengthOfLastWord("Hello World") << std::endl;
  std::cout << s.lengthOfLastWord("   fly me   to   the moon  ") << std::endl;
  std::cout << s.lengthOfLastWord("luffy is still joyboy") << std::endl;
  std::cout << s.lengthOfLastWord("a") << std::endl;
  return 0;
}