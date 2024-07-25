#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    /**
     * 1    1   1    1  2  3  3
     *        low,fast
     */
    int duplicate = 2;
    int n = nums.size();
    if (n <= duplicate) return n;
    int fast = duplicate, low = duplicate;
    for (; fast < nums.size(); fast++) {
      if (nums[fast] != nums[low - duplicate]) {
        nums[low++] = nums[fast];
      }
    }
    return low;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{1, 1, 1, 1, 2, 3, 3};
  vector<int> nums2{0, 0, 1, 1, 1, 1, 2, 3, 3};

  std::cout << s.removeDuplicates(nums1) << std::endl;
  std::cout << s.removeDuplicates(nums2) << std::endl;
  return 0;
}