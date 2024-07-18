#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    /**
     * dp[i,j] = dp[i-1][j] + dp[i][j-1];
     */
    if (obstacleGrid.size() == 0) return 1;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    int step1 = 0, step2 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
          continue;
        }
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
        } else {
          step1 = i == 0 ? 0 : obstacleGrid[i - 1][j] == 1 ? 0 : dp[i - 1][j];
          step2 = j == 0 ? 0 : obstacleGrid[i][j - 1] == 1 ? 0 : dp[i][j - 1];
          dp[i][j] = step1 + step2;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> obstacle_grid1{vector<int>{0, 0, 0}, vector<int>{0, 1, 0},
                                     vector<int>{0, 0, 0}};
  std::cout << s.uniquePathsWithObstacles(obstacle_grid1) << std::endl;
  vector<vector<int>> obstacle_grid2{vector<int>{0, 1}, vector<int>{0, 0}};
  std::cout << s.uniquePathsWithObstacles(obstacle_grid2) << std::endl;
  vector<vector<int>> obstacle_grid3{vector<int>{0, 0}, vector<int>{0, 1}};
  std::cout << s.uniquePathsWithObstacles(obstacle_grid3) << std::endl;
  vector<vector<int>> obstacle_grid4{vector<int>{1}};
  std::cout << s.uniquePathsWithObstacles(obstacle_grid4) << std::endl;

  return 0;
}