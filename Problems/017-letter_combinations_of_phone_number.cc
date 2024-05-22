#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> output;
    combinateString(output, "", digits);
    return output;
  }

 protected:
  void combinateString(vector<string>& output, std::string prefix,
                       std::string digits) {
    int n = digits.size();
    if (n == 0) {
      if (prefix != "") {
        output.push_back(prefix);
      }
      return;
    }

    for (auto c : keys_[digits.at(0)]) {
      combinateString(output, prefix + c, digits.substr(1, n - 1));
    }
  }

 private:
  std::map<char, std::string> keys_{
      {'1', std::string{}},       {'2', std::string{"abc"}},
      {'3', std::string{"def"}},  {'4', std::string{"ghi"}},
      {'5', std::string{"jkl"}},  {'6', std::string{"mon"}},
      {'7', std::string{"pqrs"}}, {'8', std::string{"tuv"}},
      {'9', std::string{"wxyz"}},
  };
};

void DumpVector(std::vector<std::string> source) {
  std::cout << "[";
  for (auto it : source) {
    std::cout << it << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  DumpVector(s.letterCombinations("23"));
  DumpVector(s.letterCombinations(""));
  DumpVector(s.letterCombinations("2"));
  return 0;
}