#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> output(n, vector<int>(n, 0));
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int i = 0, j = 0;
    int step = 0;

    while (left <= right && top <= bottom) {
      vector<int> vec;
      for (i = top, j = left; j <= right; ++j) {
        output[i][j] = ++step;
      }
      for (i = top + 1, j = right; i <= bottom; ++i) {
        output[i][j] = ++step;
      }
      if (left < right && top < bottom) {
        for (i = bottom, j = right - 1; j > left; --j) {
          output[i][j] = ++step;
        }
        for (int i = bottom, j = left; i > top; --i) {
          output[i][j] = ++step;
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

int main(int argc, char *argv[]) {
  Solution s;
  DumpVector(s.generateMatrix(3));
  DumpVector(s.generateMatrix(4));
  return 0;
}
