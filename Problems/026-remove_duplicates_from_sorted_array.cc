#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (unsigned int j = 1; j < nums.size(); ++j) {
      if (nums[i] == nums[j]) {
        continue;
      }
      nums[++i] = nums[j];
    }
    return i + 1;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> case1{1, 1, 2};
  std::vector<int> case2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::cout << s.removeDuplicates(case1) << std::endl;
  std::cout << s.removeDuplicates(case2) << std::endl;

  return 0;
}