#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    /**
     * 2,1,4,3,5
     * k
     * (1),2,(4,3,5)
     * (1)(2)(3,4,5)
     */
    quickSort(nums, 0, nums.size() - 1);
  }

 private:
  void quickSort(vector<int>& nums, int l, int r) {
    if (l < r) {
      int x = nums[l], i = l, j = r;
      while (i < j) {
        while (i < j && nums[j] >= x) {
          j--;
        }
        if (i < j) {
          nums[i++] = nums[j];
        }
        while (i < j && nums[i] < x) {
          i++;
        }
        if (i < j) {
          nums[j--] = nums[i];
        }
      }
      nums[i] = x;
      quickSort(nums, l, i - 1);
      quickSort(nums, i + 1, r);
    }
  }
};

void DumpVector(std::vector<int> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << it1 << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> nums1{2, 0, 2, 1, 1, 0};
  std::vector<int> nums2{2, 0, 1};
  std::vector<int> nums3{2, 3, 4, 5, 1};
  s.sortColors(nums1);
  s.sortColors(nums2);
  s.sortColors(nums3);
  DumpVector(nums1);
  DumpVector(nums2);
  DumpVector(nums3);

  return 0;
}