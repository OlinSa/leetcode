#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    for (int i = 0; i < intervals.size(); ++i) {
      int l = intervals[i][0], r = intervals[i][1];
      if (output.size() == 0 || output.back()[1] < l) {
        output.push_back(intervals[i]);
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
  vector<vector<int>> intervals1{{2, 3}, {6, 9}};
  vector<int> newInterval1{1, 5};
  DumpVector(s.insert(intervals1, newInterval1));

  vector<vector<int>> intervals2{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval2{4, 8};
  DumpVector(s.insert(intervals2, newInterval2));

  return 0;
}