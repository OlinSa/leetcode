#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    /**
     * dp[i][j] 表示第i,j列的最小路径和
     *
     * dp[0][0] = c[0][0] // i = 0
     * dp[i][j] = dp[i-1][j-1] + c[i][j] // j = i
     * dp[i][j] = std::min(dp[i-1][j-1],dp[i-1][j]) + c[i][j] other
     *
     * 返回dp[i][j] 最小值, j = [0, i]
     * */
    int min = INT32_MAX;
    if (triangle.size() == 0) {
      return 0;
    }
    int n = triangle.size();
    vector<vector<int>> dp(n);
    dp[0].resize(1);
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      dp[i].resize(i + 1);
      dp[i][0] = dp[i - 1][0] + triangle[i][0];
      for (int j = 1; j < i; j++) {
        dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }
      dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    for (int i = 0; i < n; ++i) {
      min = std::min(min, dp[n - 1][i]);
    }
    return min;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> triangle1{vector<int>{2}, vector<int>{3, 4},
                                vector<int>{6, 5, 7}, vector<int>{4, 1, 8, 3}};
  std::cout << s.minimumTotal(triangle1) << std::endl;
  vector<vector<int>> triangle2{vector<int>{-10}};
  std::cout << s.minimumTotal(triangle2) << std::endl;
  return 0;
}