#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row_zero(m, 0);
    vector<int> column_zero(n, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          row_zero[i] = 1;
          column_zero[j] = 1;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        bool isZero = row_zero[i] || column_zero[j];
        if (isZero) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

void DumpVector(std::vector<std::vector<int>> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << "[";
    for (auto it2 : it1) {
      std::cout << it2 << ",";
    }
    std::cout << "]";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;

  vector<vector<int>> matrix1{vector<int>{1, 1, 1}, vector<int>{1, 0, 1},
                              vector<int>{1, 1, 1}};
  s.setZeroes(matrix1);
  DumpVector(matrix1);

  vector<vector<int>> matrix2{vector<int>{0, 1, 2, 0}, vector<int>{3, 4, 5, 2},
                              vector<int>{1, 3, 1, 5}};
  s.setZeroes(matrix2);
  DumpVector(matrix2);

  return 0;
}