#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    int n1 = num1.size();
    int n2 = num2.size();

    vector<int> ans(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; --i) {
      int x = num1[i] - '0';
      for (int j = n2 - 1; j >= 0; --j) {
        int y = num2[j] - '0';
        ans[i + j + 1] += x * y;
      }
    }
    for (int i = n1 + n2 - 1; i > 0; --i) {
      ans[i - 1] += ans[i] / 10;
      ans[i] %= 10;
    }
    string result;
    for (auto& e : ans) {
      result.push_back(e + '0');
    }
    return result.size() > 1 && result[0] == '0'
               ? result.substr(1, result.size() - 1)
               : result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.multiply("2", "3") << std::endl;
  std::cout << s.multiply("123", "456") << std::endl;
  return 0;
}