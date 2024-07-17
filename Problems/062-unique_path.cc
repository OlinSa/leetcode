#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 1;
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));

    // dp[i,j] = dp[i-1][j] + dp[i][j-1];

    int step1 = 0, step2 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[0][0] = 1;
          continue;
        }

        step1 = i == 0 ? 0 : dp[i - 1][j];
        step2 = j == 0 ? 0 : dp[i][j - 1];
        dp[i][j] = step1 + step2;
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.uniquePaths(3, 7) << std::endl;
  std::cout << s.uniquePaths(3, 2) << std::endl;
  std::cout << s.uniquePaths(7, 3) << std::endl;
  std::cout << s.uniquePaths(3, 3) << std::endl;

  return 0;
}