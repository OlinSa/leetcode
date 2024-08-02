#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;

    int longest = 1;
    std::sort(nums.begin(), nums.end());
    int continuous_cnt = 1;
    for (unsigned int i = 1; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] == 1) {
        longest = std::max(++continuous_cnt, longest);
      } else if (nums[i] - nums[i - 1] == 0) {
      } else {
        continuous_cnt = 1;
      }
    }
    return longest;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{100, 4, 200, 1, 3, 2};
  std::cout << s.longestConsecutive(nums1) << std::endl;
  vector<int> nums2{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  std::cout << s.longestConsecutive(nums2) << std::endl;
  vector<int> nums3{1, 2, 0, 1};
  std::cout << s.longestConsecutive(nums3) << std::endl;
  return 0;
}