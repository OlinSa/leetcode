#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int maxPos = 0;
    int step = 0;
    int end = 0;
    for (int i = 0; i < n - 1; ++i) {
      maxPos = std::max(maxPos, i + nums[i]);
      if (i == end) {
        end = maxPos;
        step++;
      }
    }
    return step;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::vector<int> case1{2, 3, 1, 1, 4};
  std::cout << s.jump(case1) << std::endl;
  std::vector<int> case2{2, 3, 0, 1, 4};
  std::cout << s.jump(case2) << std::endl;
  return 0;
}