#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    vector<int> output(n + 1);
    int carry = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      sum = digits[i] + carry;
      if (i == n - 1) {
        sum++;
      }
      output[i + 1] = sum % 10;
      carry = sum / 10;
    }
    output[0] = carry;
    return output[0] == 0 ? vector<int>(++output.begin(), output.end())
                          : output;
  }
};

void DumpVector(std::vector<int> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << it1 << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> digits1{1, 2, 3};
  DumpVector(s.plusOne(digits1));
  vector<int> digits2{4, 3, 2, 1};
  DumpVector(s.plusOne(digits2));
  vector<int> digits3{0};
  DumpVector(s.plusOne(digits3));
  vector<int> digits4{9, 9, 9};
  DumpVector(s.plusOne(digits4));
  return 0;
}