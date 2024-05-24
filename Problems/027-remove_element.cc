#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (unsigned int j = 0; j < nums.size(); j++) {
      if (nums[j] != val) {
        nums[i++] = nums[j];
      }
    }
    return i;
  }
};

void dumpVector(const vector<int>& nums) {
  std::cout << "{";
  for (auto n : nums) {
    std::cout << n << ",";
  }
  std::cout << "}" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> case1{3, 2, 2, 3};
  std::vector<int> case2{0, 1, 2, 2, 3, 0, 4, 2};

  std::cout << s.removeElement(case1, 3) << std::endl;
  std::cout << s.removeElement(case2, 2) << std::endl;

  dumpVector(case1);
  dumpVector(case2);

  return 0;
}