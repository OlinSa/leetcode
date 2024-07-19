#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    auto splice = [](const string& str, char delim) -> vector<string> {
      vector<string> output;
      string cstr;
      for (auto s : str) {
        if (s == delim) {
          output.push_back(std::move(cstr));
          cstr.clear();
        } else {
          cstr += s;
        }
      }
      output.push_back(std::move(cstr));
      return output;
    };
    std::string simple_path;
    std::vector<string> stk;
    std::vector<string> ans = splice(path, '/');
    for (auto s : ans) {
      if (s == "..") {
        if (!stk.empty()) {
          stk.pop_back();
        }
      } else if (!s.empty() && s != ".") {
        stk.push_back(std::move(s));
      }
    }
    if (stk.empty()) {
      simple_path += '/';
    } else {
      for (auto s : stk) {
        simple_path += "/" + s;
      }
    }

    return simple_path;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.simplifyPath("/home/") << std::endl;
  std::cout << s.simplifyPath("/../") << std::endl;
  std::cout << s.simplifyPath("/a/b/../../c/") << std::endl;
  std::cout << s.simplifyPath("/home/user/Documents/../Pictures") << std::endl;
  return 0;
}