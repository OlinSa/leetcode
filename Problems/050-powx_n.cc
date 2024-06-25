#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1.0;
    }
    double ans = 1, bose = (double)(n > 0 ? x : 1 / x);
    // 这里处理 negation of -2147483648 cannot be represented in type 'int';
    long long b = n;
    if (b < 0) {
      b = -b;
    }
    while (b > 0) {
      if ((b & 1) == 1) {
        ans *= bose;
      }
      bose = bose * bose;
      b >>= 1;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.myPow(2.0, 10) << std::endl;
  std::cout << s.myPow(2.1, 3) << std::endl;
  std::cout << s.myPow(2.0, -2) << std::endl;
  std::cout << s.myPow(1.0, -2147483648) << std::endl;
  return 0;
}