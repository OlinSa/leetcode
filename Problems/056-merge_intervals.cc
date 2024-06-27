#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> output;
    int n = intervals.size();
    if (n == 0 || n == 1) return intervals;

    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; ++i) {
      int l = intervals[i][0], r = intervals[i][1];
      if (output.empty() || output.back()[1] < l) {
        output.push_back(vector<int>{l, r});
      } else {
        output.back()[1] = std::max(output.back()[1], r);
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
  vector<vector<int>> intervals1{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> intervals2{{1, 4}, {4, 5}};
  vector<vector<int>> intervals3{{2, 3}, {1, 5}};

  DumpVector(s.merge(intervals1));
  DumpVector(s.merge(intervals2));
  DumpVector(s.merge(intervals3));
  return 0;
}