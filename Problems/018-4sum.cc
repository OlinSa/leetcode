#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();

    if (n < 4) {
      return ans;
    }

    sort(nums.begin(), nums.end());
    /**
     * 双指针法: 遍历两个2数， 然后使用双指针寻找其他合适的值
     * i   j l     r
     * -2 -1 0 0 1 2
     */
    for (unsigned long i = 0; i < n - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (unsigned long j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int l = j + 1, r = n - 1;
        while (l < r) {
          long sum =
              (long)nums[i] + nums[j] + nums[l] +
              nums[r];  // untime error: signed integer overflow: 2000000000 +
                        // 1000000000 cannot be represented in type 'value_type'
                        // (aka 'int') (solution.cpp) SUMMARY:
                        // UndefinedBehaviorSanitizer: undefined-behavior
                        // prog_joined.cpp:34:50
          if (sum > target) {
            r--;
          } else if (sum < target) {
            l++;
          } else {
            ans.push_back(std::vector<int>{nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[++l]);
            while (l < r && nums[r] == nums[--r]);
          }
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
  std::vector<int> source0{1, 0, -1, 0, -2, 2};
  std::vector<int> source1{2, 2, 2, 2, 2};
  std::vector<int> source2{-2, -1, -1, 1, 1, 1, 2, 2};
  DumpVector(s.fourSum(source0, 0));
  DumpVector(s.fourSum(source1, 8));
  DumpVector(s.fourSum(source2, 0));

  return 0;
}