#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    if (n == 1) return nums[0] == target;

    int l = 0, r = n - 1;
    int mid;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] == target) {
        return true;
      }
      /*
      if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
        l++;
        r--;
      } else if (nums[l] < nums[r]) {
        if (target > nums[mid]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } else if (nums[mid] < nums[l]) {
        if (target > nums[mid] && target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid + 1;
        }
      } else if (target > nums[l] && nums[mid] > nums[r]) {
        if (target > nums[l] && target <= nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      */
      if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
        l++;
        r--;
      } else if (nums[l] <= nums[mid]) {
        if (target >= nums[l] && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[n - 1]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{2, 5, 6, 0, 0, 1, 2};

  std::cout << s.search(nums1, 0) << std::endl;
  std::cout << s.search(nums1, 3) << std::endl;

  vector<int> nums2{1, 0, 1, 1, 1};
  std::cout << s.search(nums2, 0) << std::endl;

  vector<int> nums3{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << s.search(nums3, 13) << std::endl;
  return 0;
}