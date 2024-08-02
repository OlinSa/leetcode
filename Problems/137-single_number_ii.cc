#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    std::map<int, int> num_map;

    for (auto& num : nums) {
      num_map[num]++;
    }
    for (auto it = num_map.begin(); it != num_map.end(); it++) {
      if (it->second == 1) {
        return it->first;
      }
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  Solution s;

  vector<int> nums1{2, 2, 3, 2};
  std::cout << s.singleNumber(nums1) << std::endl;

  vector<int> nums2{0, 1, 0, 1, 0, 1, 99};
  std::cout << s.singleNumber(nums2) << std::endl;

  return 0;
}