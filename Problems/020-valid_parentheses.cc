#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> que;
    for (auto c : s) {
      switch (c) {
        case '(':
        case '{':
        case '[':
          que.push(c);
          break;
        case ')':
          if (que.empty() || que.top() != '(') return false;
          que.pop();
          break;
        case '}':
          if (que.empty() || que.top() != '{') return false;
          que.pop();
          break;
        case ']':
          if (que.empty() || que.top() != '[') return false;
          que.pop();
          break;
        default:
          break;
      }
    }
    return que.size() == 0;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.isValid(std::string("()")) << std::endl;
  std::cout << s.isValid(std::string("()[]{}")) << std::endl;
  std::cout << s.isValid(std::string("(]")) << std::endl;
  return 0;
}