#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> output;
    std::sort(nums.begin(), nums.end());
    dfs(false, 0, output, nums);
    return output;
  }

 private:
  void dfs(bool chosePrev, unsigned int cur, vector<vector<int>>& output,
           const vector<int>& nums) {
      if (cur == nums.size()) {
        output.push_back(temp_);
        return;
      }
      std::cout<<"1 cur:"<<cur<<std::endl;
      dfs(false, cur + 1, output, nums);
      std::cout<<"2 cur:"<<cur<<std::endl;
      temp_.push_back(nums[cur]);
      dfs(true, cur + 1, output, nums);
      temp_.pop_back();
  }
  vector<int> temp_;
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
  vector<int> nums1{1,2,2};
  vector<int> nums2{0};
  DumpVector(s.subsetsWithDup(nums1));
  DumpVector(s.subsetsWithDup(nums2));
}