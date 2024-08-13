
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    /**
     * 这里需要注意， 这里较常规的动态规化， 多了一个条件最小初始值
     *
     * 需要统计两个数值
     * 1. 到达该点的数值和
     * 2. 到达该点的最小初始值
     *
     * 条件一和二 无法直接适用 动态规化， 有两个条件同时约束。
     * 故采取从右下到左上来搜索, 即无需关心路径和问题 dp[i][j]
     * 表示从坐标i,j到达终点所需最小初始值, 只要从i,j到终点路径和 > dp[i][j],
     * 即可保证(i,j) 可到终点
     *
     * dp[i][j] = std::max(std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1)
     */
    if (dungeon.empty()) return -1;
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    int min_value = 1;
    dp[m - 1][n - 1] = std::max(min_value - dungeon[m - 1][n - 1], 1);
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i == m - 1 && j == n - 1) continue;
        if (i == m - 1) {
          min_value = dp[i][j + 1];
        } else if (j == n - 1) {
          min_value = dp[i + 1][j];
        } else {
          min_value = std::min(dp[i][j + 1], dp[i + 1][j]);
        }
        dp[i][j] = std::max(min_value - dungeon[i][j], 1);
      }
    }
    return dp[0][0];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> dungeon1{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
  vector<vector<int>> dungeon2{{0}};

  std::cout << s.calculateMinimumHP(dungeon1) << std::endl;
  std::cout << s.calculateMinimumHP(dungeon2) << std::endl;

  return 0;
}