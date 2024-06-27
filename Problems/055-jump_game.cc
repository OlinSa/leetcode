#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();

    int right_pos = nums[0];

    for (int i = 0; i < n; ++i) {
      if (i <= right_pos) {
        right_pos = std::max(i + nums[i], right_pos);
        if (right_pos >= n - 1) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{2, 3, 1, 1, 4};
  std::cout << s.canJump(nums1) << std::endl;
  vector<int> nums2{3, 2, 1, 0, 4};
  std::cout << s.canJump(nums2) << std::endl;
  vector<int> nums3{0};
  std::cout << s.canJump(nums3) << std::endl;
  vector<int> nums4{3, 0, 8, 2, 0, 0, 1};
  std::cout << s.canJump(nums4) << std::endl;
  return 0;
}