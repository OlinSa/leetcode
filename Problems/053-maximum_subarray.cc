#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max_ans = nums[0], prev_ans = 0;
    for (const auto& x : nums) {
      prev_ans = max(prev_ans + x, x);
      max_ans = max(prev_ans, max_ans);
    }
    return max_ans;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> nums1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << s.maxSubArray(nums1) << std::endl;
  std::vector<int> nums2{1};
  std::cout << s.maxSubArray(nums2) << std::endl;
  std::vector<int> nums3{5, 4, -1, 7, 8};
  std::cout << s.maxSubArray(nums3) << std::endl;
  return 0;
}