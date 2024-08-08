#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    std::map<int, int> fre_map;
    int n = nums.size();
    for (auto num : nums) {
      if (++fre_map[num] > n / 2) {
        return num;
      }
    }
    return 0;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> nums1{3, 2, 3};
  std::vector<int> nums2{2, 2, 1, 1, 1, 2, 2};
  std::cout << s.majorityElement(nums1) << std::endl;
  std::cout << s.majorityElement(nums2) << std::endl;

  return 0;
}