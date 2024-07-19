#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      if (matrix[i][0] <= target && matrix[i][n - 1] >= target) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j] == target) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> matrix{std::vector<int>{1, 3, 5, 7},
                             std::vector<int>{10, 11, 16, 20},
                             std::vector<int>{23, 30, 34, 60}};
  std::cout << s.searchMatrix(matrix, 3) << std::endl;
  std::cout << s.searchMatrix(matrix, 13) << std::endl;

  return 0;
}