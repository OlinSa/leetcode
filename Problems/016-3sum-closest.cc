#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    unsigned long n = nums.size();
    int ret = 0;
    int min_diff = INT32_MAX;
    if (n < 3) return 0;
    std::sort(nums.begin(), nums.end());

    for (unsigned long i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate number
      unsigned long l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r] - target;
        if (abs(sum) < min_diff) {
          ret = nums[i] + nums[l] + nums[r];
          min_diff = abs(sum);
          if (min_diff == 0) {
            return ret;
          }
        }

        if (sum > 0) {
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          return ret;
        }
      }
    }

    return ret;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> case1{-1, 2, 1, 4};
  std::vector<int> case2{0, 0, 0};
  std::vector<int> case3{1, 1, 1, 1};

  std::cout << s.threeSumClosest(case1, 1) << std::endl;
  std::cout << s.threeSumClosest(case2, 1) << std::endl;
  std::cout << s.threeSumClosest(case3, 0) << std::endl;

  return 0;
}