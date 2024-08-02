#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    int row = rowIndex + 1;
    vector<vector<int>> output(row + 1);
    for (int i = 0; i < row; ++i) {
      output[i].resize(i + 1);
      output[i][0] = output[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        output[i][j] += output[i - 1][j - 1];
        output[i][j] += output[i - 1][j];
      }
    }
    return output[rowIndex];
  }
};

void DumpVector(std::vector<int> source) {
  std::cout << "[";
  for (auto it : source) {
    std::cout << it << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  DumpVector(s.getRow(3));
  DumpVector(s.getRow(0));
  DumpVector(s.getRow(1));

  return 0;
}