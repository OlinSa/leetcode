
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    /**
     * dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
     * dp[0] = nums[0]
     * dp[1] = nums[1]
     */
    int n = nums.size();
    if (n == 0) return -1;
    if (n == 1) {
      return nums[0];
    }

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{1, 2, 3, 1};
  vector<int> nums2{2, 7, 9, 3, 1};
  vector<int> nums3{2, 1};
  std::cout << s.rob(nums1) << std::endl;
  std::cout << s.rob(nums2) << std::endl;
  std::cout << s.rob(nums3) << std::endl;
  return 0;
}