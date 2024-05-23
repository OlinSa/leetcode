#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> output;
    generateAll(output, "", n * 2);
    return output;
  }

 private:
  bool isValid(const std::string& s) {
    int blance = 0;
    for (auto c : s) {
      if (c == '(') {
        blance++;
      } else {
        blance--;
      }
      if (blance < 0) return false;
    }
    return blance == 0;
  }

  void generateAll(vector<string>& output, string cur, int n) {
    if (cur.size() == n) {
      if (isValid(cur)) {
        output.push_back(cur);
      }
      return;
    }
    generateAll(output, cur + '(', n);
    generateAll(output, cur + ')', n);
  }
};

void dump(const vector<string>& output) {
  for (auto s : output) {
    std::cout << s << ",";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;

  dump(s.generateParenthesis(3));
  dump(s.generateParenthesis(1));

  return 0;
}
