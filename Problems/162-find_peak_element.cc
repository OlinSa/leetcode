#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    /**
     * binary search
     *  nums[i] > nums[i-1] && nums[i] > nums[i+1] return i
     *  nums[i] < nums[i+1] ==> [i+1,r]
     *  nums[i] > nums[i+1] ==> [l,i-1]
     *
     *        *
     *      * *
     *   *  * *  *
     **/
    int l = 0, r = nums.size() - 1;
    int i;
    while (l < r) {
      i = (l + r) / 2;
      if (i == l || i == r) {
        if (i == l && nums[i] > nums[i + 1]) return i;
        if (i == r && nums[i] > nums[i - 1]) return i;
      } else {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
          return i;
        }
      }

      if (nums[i] < nums[i + 1]) {
        l = i + 1;
      } else {
        r = i - 1;
      }
    }
    return l;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{1, 2, 3, 1};
  vector<int> nums2{1, 2, 1, 3, 5, 6, 4};
  vector<int> nums3{1, 2};
  vector<int> nums4{1};
  std::cout << s.findPeakElement(nums1) << std::endl;
  std::cout << s.findPeakElement(nums2) << std::endl;
  std::cout << s.findPeakElement(nums3) << std::endl;
  std::cout << s.findPeakElement(nums4) << std::endl;
  return 0;
}