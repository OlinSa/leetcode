
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    if (nums.empty()) return "";
    std::sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
      return to_string(x) + to_string(y) > to_string(y) + to_string(x);
    });

    // 处理最大值为0的问题
    if (nums[0] == 0) return "0";
    string num;
    for (auto c : nums) {
      num += std::to_string(c);
    }
    return num;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> nums1{10, 2};
  vector<int> nums2{3, 30, 34, 5, 9};
  vector<int> nums3{111311, 1113};
  vector<int> nums4{0, 0};
  std::cout << s.largestNumber(nums1) << std::endl;
  std::cout << s.largestNumber(nums2) << std::endl;
  std::cout << s.largestNumber(nums3) << std::endl;
  std::cout << s.largestNumber(nums4) << std::endl;
  return 0;
}