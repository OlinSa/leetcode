#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int sqrt = 0;
    for (int i = 1; i <= x; ++i) {
      if ((long long)i * i == x) return i;
      if ((long long)i * i > x) break;
      sqrt = i;
    }
    return sqrt;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.mySqrt(0) << std::endl;
  std::cout << s.mySqrt(1) << std::endl;
  std::cout << s.mySqrt(2) << std::endl;
  std::cout << s.mySqrt(4) << std::endl;
  std::cout << s.mySqrt(8) << std::endl;
  std::cout << s.mySqrt(9) << std::endl;
  return 0;
}