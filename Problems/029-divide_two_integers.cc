#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    /*
     * 这里借鉴了其他的方法， int的范围为[-2^31, -2^31 -1],
     * 如果直接将负数转成整数， 则会溢出 直接将dividend和divisor都转成负数计算
     *
     * 直接采用除法->减法， 时间太长, 这里采用方法2
     * x / y = z， 这里x y都是负数
     *  ==> z * y >= x > (z - 1) *y
     *  寻找最大的z
     *
     */
    int sign = 1;
    if (divisor == 0) return 0;

    // 这里quotient INT32_MIN / 1 = INT32_MIN,  right
    // 无法无法指向abs(INT32_MIN), 会造成溢出。 只要divisor > 1,
    // quotient就不会溢出
    if (dividend == INT32_MIN) {
      if (divisor == 1) {
        return INT32_MIN;
      } else if (divisor == -1) {
        return INT32_MAX;
      }
    }

    if (dividend > 0) {
      dividend = -dividend;
      sign = !sign;
    }
    if (divisor > 0) {
      divisor = -divisor;
      sign = !sign;
    }

    int left = 1, right = INT32_MAX;
    int ans = 0;
    int mid = 0;

    while (left <= right) {
      mid = left + ((right - left) >> 1);
      if (checkMatchCondition(dividend, divisor, mid)) {
        ans = mid;
        if (mid == INT32_MAX) break;  // avoid flow
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return sign ? ans : -ans;
  }

 private:
  // precondition: x < 0, y < 0, z > 0
  bool checkMatchCondition(int x, int y, int z) {
    // std::cout << "x:" << x << ",y:" << y << ",z:" << z << std::endl;
    // z * y >= x > (z - 1) *y
    // quick add
    int result = 0, add = y;
    while (z) {
      if (z & 1) {  // odd
        if (result < x - add) {
          return false;
        }
        result += add;
      }
      if (z != 1) {  // even
        if (add < x - add) {
          return false;
        }
        add += add;
      }

      z >>= 1;
    }
    return true;
  }

  int divideSimple(int dividend, int divisor) {
    int quotient = 0;
    int sign = ((dividend >= 0) ? 1 : -1) * ((divisor >= 0) ? 1 : -1);
    if (divisor == 0) return 0;

    if (dividend > 0) {
      dividend = -dividend;
    }
    if (divisor > 0) {
      divisor = -divisor;
    }
    while (dividend <= divisor) {
      ++quotient;
      dividend -= divisor;
    }
    return sign * quotient;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.divide(10, 3) << std::endl;
  std::cout << s.divide(7, -3) << std::endl;
  std::cout << s.divide(1, 0) << std::endl;
  std::cout << s.divide(1, 1) << std::endl;
  std::cout << s.divide(-2147483648, -1) << std::endl;
  std::cout << s.divide(-2147483648, 1) << std::endl;
  return 0;
}