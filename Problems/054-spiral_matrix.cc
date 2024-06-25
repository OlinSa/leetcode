#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> output;
    int left = 0, top = 0, right = matrix[0].size() - 1,
        bottom = matrix.size() - 1;

    int i = 0, j = 0;

    while (left <= right && top <= bottom) {
      for (i = top, j = left; j <= right; ++j) {
        output.push_back(matrix[i][j]);
      }
      for (i = top + 1, j = right; i <= bottom; ++i) {
        output.push_back(matrix[i][j]);
      }
      if (left < right && top < bottom) {
        for (i = bottom, j = right - 1; j > left; --j) {
          output.push_back(matrix[i][j]);
        }
        for (int i = bottom, j = left; i > top; --i) {
          output.push_back(matrix[i][j]);
        }
      }

      top++;
      right--;
      left++;
      bottom--;
    }
    return output;
  }
};

void DumpVector(std::vector<int> source) {
  for (auto it1 : source) {
    std::cout << it1 << ",";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> matrix1{vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
                              vector<int>{7, 8, 9}};
  DumpVector(s.spiralOrder(matrix1));
  vector<vector<int>> matrix2{vector<int>{1, 2, 3, 4}, vector<int>{5, 6, 7, 8},
                              vector<int>{9, 10, 11, 12}};
  DumpVector(s.spiralOrder(matrix2));
  return 0;
}