#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    std::stack<int> constant_stk;
    for (auto token : tokens) {
      if (!isOperator(token)) {
        constant_stk.push(std::stoi(token));
      } else {
        int top2 = constant_stk.top();
        constant_stk.pop();
        int top1 = constant_stk.top();
        constant_stk.pop();

        switch (token[0]) {
          case '+': {
            constant_stk.push(top1 + top2);
            break;
          }
          case '-': {
            constant_stk.push(top1 - top2);
            break;
          }
          case '*': {
            constant_stk.push(top1 * top2);
            break;
          }
          case '/': {
            constant_stk.push(top1 / top2);
            break;
          }
          default: {
          }
        }
      }
    }
    return constant_stk.top();
  }

 private:
  bool isOperator(const string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
  }
};

int main(int argc, char* argv[]) {
  Solution s;

  vector<string> tokens1 = {"2", "1", "+", "3", "*"};
  vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  vector<string> tokens3 = {"10", "6", "9",  "3", "+", "-11", "*",
                            "/",  "*", "17", "+", "5", "+"};

  std::cout << s.evalRPN(tokens1) << std::endl;
  std::cout << s.evalRPN(tokens2) << std::endl;
  std::cout << s.evalRPN(tokens3) << std::endl;

  return 0;
}