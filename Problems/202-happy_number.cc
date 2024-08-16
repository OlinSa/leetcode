#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    /**
     * 结束条件
     *
     * 1. 无限循环  not happy number
     * 2. 结果为1   is happy number
     */
    std::map<int, int> freq_count;

    while (n != 1) {
      if (freq_count[n] != 0) {
        return false;
      }
      ++freq_count[n];
      int tmp = n;
      n = 0;
      while (tmp > 0) {
        int unit = tmp % 10;
        n += (unit * unit);
        tmp /= 10;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << s.isHappy(19) << std::endl;
  std::cout << s.isHappy(2) << std::endl;

  return 0;
}