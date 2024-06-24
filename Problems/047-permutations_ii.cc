#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> output;
    vis.resize(nums.size(), 0);
    sort(nums.begin(), nums.end());
    dfs(output, nums, 0);
    return output;
  }

 private:
  void dfs(vector<vector<int>> &output, vector<int> &nums, int idx) {
    if (idx >= nums.size()) {
      output.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
        continue;
      }
      path.push_back(nums[i]);
      vis[i] = 1;
      dfs(output, nums, idx + 1);
      path.pop_back();
      vis[i] = 0;
    }
  }

 private:
  vector<int> vis;
  vector<int> path;
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
  // vector<int> case1{1, 1, 2};
  // DumpVector(s.permuteUnique(case1));
  // vector<int> case2{1, 2, 3};
  // DumpVector(s.permuteUnique(case2));
  vector<int> case3{3, 3, 0, 3};
  DumpVector(s.permuteUnique(case3));
  return 0;
}