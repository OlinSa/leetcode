#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> output;
    temp.reserve(nums.size());

    dfs(output, nums, 0);
    return output;
  }

 private:
  void dfs(vector<vector<int>>& output, vector<int>& nums, int cur) {
    if (cur == nums.size()) {
      output.push_back(temp);
      return;
    }
    temp.push_back(nums[cur]);
    dfs(output, nums, cur + 1);
    temp.pop_back();
    dfs(output, nums, cur + 1);
  }
  vector<int> temp;
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
  vector<int> case1{1, 2, 3};
  DumpVector(s.subsets(case1));

  return 0;
}