#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    /**
     * matrix[i][j] = matrix[j][column-i-1];
     * 不使用额外数组复杂度较高
     *
     * 使用折叠法:
     * 两次折叠， 先横向折叠， 再对角折叠
     * 1 2 3      7 8 9            7 4 1
     * 4 5 6 =>   4 5 6  ==>       8 5 2
     * 7 8 9      1 2 3            9 6 3
     *
     * 1. i = [0, matrix.size())
     * matrix[i][j] = matrix[column-i-1][j]
     * 2.
     * matrix[i][j] = matrix[j][i]
     */
    int row = matrix.size();
    int column = matrix[0].size();
    int temp = 0;
    for (int i = 0; i < row / 2; ++i) {
      for (int j = 0; j < column; ++j) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[column - i - 1][j];
        matrix[column - i - 1][j] = temp;
      }
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j <= i; ++j) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
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
  vector<vector<int>> matrix1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix2{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(matrix1);
  s.rotate(matrix2);
  DumpVector(matrix1);
  DumpVector(matrix2);
}