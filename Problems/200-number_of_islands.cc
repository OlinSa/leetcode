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
  int numIslands(vector<vector<char>>& grid) {
    int lands = 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> mask(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          int area = dfs(i, j, mask, grid);
          if (area != 0) {
            lands++;
          }
        }
      }
    }
    return lands;
  }

 private:
  int dfs(int i, int j, vector<vector<bool>>& mask,
          const vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) return 0;
    if (mask[i][j]) return 0;
    if (grid[i][j] != '1') return 0;
    mask[i][j] = true;

    return 1 + dfs(i, j - 1, mask, grid) + dfs(i, j + 1, mask, grid) +
           dfs(i - 1, j, mask, grid) + dfs(i + 1, j, mask, grid);
  }
};

int main(int argc, char* argv[]) {
  Solution s;

  vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};

  vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};

  std::cout << s.numIslands(grid1) << std::endl;
  std::cout << s.numIslands(grid2) << std::endl;
  return 0;
}