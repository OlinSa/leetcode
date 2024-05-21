#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    unsigned long n = nums.size();
    vector<vector<int>> ans;
    if (n < 3) return ans;
    std::sort(nums.begin(), nums.end());

    // for (unsigned i = 0; i < nums.size(); i++) {
    //   for (unsigned int j = i + 1; j < nums.size(); j++) {
    //     if (nums[j] == nums[i]) continue;
    //     for (unsigned int k = j + 1; k < nums.size(); k++) {
    //       if (nums[k] == nums[j]) continue;
    //       if (nums[i] + nums[j] + nums[k] == 0) {
    //         ans.push_back(std::vector<int>{nums[i], nums[j], nums[k]});
    //       }
    //     }
    //   }
    // }

    for (int i = 0; i < n - 2; i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate number
      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum > 0) {
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          ans.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
          // skip duplicate number
          while (l < r && nums[l] == nums[++l]);
          while (l < r && nums[r] == nums[--r]);
        }
      }
    }

    return ans;
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
  std::vector<int> source0{-4, -1, -1, 0, 1, 2};
  std::vector<int> source1{-1, 0, 1, 2, -1, -4};
  std::vector<int> source2{0, 1, 1};
  std::vector<int> source3{0, 0, 0};
  std::vector<int> source4{1, -1, -1, 0};
  // DumpVector(s.threeSum(source1));
  // DumpVector(s.threeSum(source2));
  // DumpVector(s.threeSum(source3));
  DumpVector(s.threeSum(source4));
  return 0;
}