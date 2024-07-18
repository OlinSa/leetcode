#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    // dp[i,j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
    if (grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    int step1 = 0, step2 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[0][0] = grid[0][0];
          continue;
        }
        int sum = 0;
        step1 = i == 0 ? 0 : dp[i - 1][j];
        step2 = j == 0 ? 0 : dp[i][j - 1];
        if (i == 0 ||
            j == 0) {  // The edge side is unreachable, there is only one path
          sum = step1 + step2;
        } else {
          sum = std::min(step1, step2);
        }

        dp[i][j] = sum + grid[i][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> grid1{vector<int>{1, 3, 1}, vector<int>{1, 5, 1},
                            vector<int>{4, 2, 1}};
  std::cout << s.minPathSum(grid1) << std::endl;
  vector<vector<int>> grid2{vector<int>{1, 2, 3}, vector<int>{4, 5, 6}};
  std::cout << s.minPathSum(grid2) << std::endl;
  vector<vector<int>> grid3{vector<int>{1}};
  std::cout << s.minPathSum(grid3) << std::endl;
  return 0;
}