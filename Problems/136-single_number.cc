#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    /**
     * a ^ 0 = a
     * b ^ b = 0
     * a ^ b ^ a = b ^ a ^ a = b
     */
    int single = 0;
    for (auto& n : nums) {
      single ^= n;
    }
    return single;
  }
};

int main(int argc, char* argv[]) {
  Solution s;

  vector<int> nums1{2, 2, 1};
  std::cout << s.singleNumber(nums1) << std::endl;

  vector<int> nums2{4, 1, 2, 1, 2};
  std::cout << s.singleNumber(nums2) << std::endl;

  vector<int> nums3{1};
  std::cout << s.singleNumber(nums3) << std::endl;
  return 0;
}