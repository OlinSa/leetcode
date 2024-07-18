#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string output;
    int carry = 0;
    int sum;

    auto src1_it = a.rbegin();
    auto src2_it = b.rbegin();

    while (src1_it != a.rend() && src2_it != b.rend()) {
      sum = *src1_it - '0' + *src2_it - '0' + carry;

      carry = updateData(output, sum);

      src1_it++;
      src2_it++;
    }
    while (src1_it != a.rend()) {
      sum = *src1_it - '0' + carry;
      carry = updateData(output, sum);
      src1_it++;
    }
    while (src2_it != b.rend()) {
      sum = *src2_it - '0' + carry;
      carry = updateData(output, sum);
      src2_it++;
    }
    if (carry != 0) {
      updateData(output, carry);
    }
    std::reverse(output.begin(), output.end());
    return output;
  }

 private:
  int updateData(string& output, int n) {
    int carry = n / 2;
    n %= 2;

    output.push_back(n + '0');
    return carry;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  // 11 1 -> 100
  // 1010 1011 -> 10101
  std::cout << s.addBinary("11", "1") << std::endl;
  std::cout << s.addBinary("1010", "1011") << std::endl;
  std::cout << s.addBinary("0", "0") << std::endl;
  std::cout << s.addBinary("1111", "1111") << std::endl;
  return 0;
}