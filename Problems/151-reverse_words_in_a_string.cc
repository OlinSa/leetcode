#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    std::string result;
    std::vector<std::string> split_str = split(s, ' ');
    for (int i = split_str.size() - 1; i >= 0; i--) {
      result.append(split_str[i]);
      if (i != 0) {
        result.append(" ");
      }
    }
    return result;
  }

  std::vector<std::string> split(const std::string &input, char delimiter) {
    std::stringstream ss(input);
    std::vector<std::string> tokens;
    std::string token;

    while (ss >> token) {
      tokens.push_back(token);
    }
    return tokens;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.reverseWords("the sky is blue") << std::endl;
  std::cout << s.reverseWords("  hello world  ") << std::endl;
  std::cout << s.reverseWords("a good   example") << std::endl;
  return 0;
}