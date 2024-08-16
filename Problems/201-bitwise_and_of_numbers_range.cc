#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    /**
     *
     * 暴力算法
     * int ans = left;
     * while (++left <= right) {
     *  ans &= left;
     * }
     * return ans;
     *
     *  9: 1001
     * 10: 1010
     * 11: 1011
     * 12  1100
     *      ###
     * 寻规律， 假设前i位相同， 第i+1不同。 m < n 必然 存在一个数x1其i+1位为0，
     * x1+1其第i+1位为1
     *
     */
    int shift = 0;
    while (left < right) {
      left >>= 1;
      right >>= 1;
      ++shift;
    }

    return left << shift;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << s.rangeBitwiseAnd(5, 7) << std::endl;
  std::cout << s.rangeBitwiseAnd(0, 0) << std::endl;
  std::cout << s.rangeBitwiseAnd(1, 2147483647) << std::endl;

  return 0;
}