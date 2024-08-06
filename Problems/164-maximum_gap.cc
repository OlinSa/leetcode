#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    std::sort(nums.begin(), nums.end());
    int max_gap = INT32_MIN;
    for (int i = 0; i < n - 1; i++) {
      max_gap = std::max(std::abs(nums[i + 1] - nums[i]), max_gap);
    }
    return max_gap;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{3, 6, 9, 1};
  vector<int> nums2{10};

  std::cout << s.maximumGap(nums1) << std::endl;
  std::cout << s.maximumGap(nums2) << std::endl;

  return 0;
}