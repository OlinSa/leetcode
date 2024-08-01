#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> output(numRows);

    for (int i = 0; i < numRows; ++i) {
      output[i].resize(i + 1);
      output[i][0] = output[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        output[i][j] += output[i - 1][j - 1];
        output[i][j] += output[i - 1][j];
      }
    }
    return output;
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
  DumpVector(s.generate(5));
  DumpVector(s.generate(1));
  return 0;
}