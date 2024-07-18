#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    /**
     * dp[0] = 1
     * dp[1] = 2
     * dp[i] = dp[i-1] + dp[i-2]
     */
    if (n == 1) return 1;
    if (n == 2) return 2;
    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.climbStairs(2) << std::endl;
  std::cout << s.climbStairs(3) << std::endl;
  return 0;
}