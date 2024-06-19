#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int volume = 0;
    int n = height.size();

    if (n <= 1) {
      return 0;
    }

    vector<int> left_max(n, 0);
    vector<int> right_max(n, 0);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];

    /**
     * ===>
     * [1,n-1] leftMax[i] = max(leftMax[i-1], height[i]);
     *
     * <====
     * [0,n-2] rightMax[i] = max(rightMax[i+1], height[i]);
     *
     * [0,n) volume[i] = min(leftMax[i],rightMax[i]) - height[i]
     */

    for (int i = 1; i < n; ++i) {
      left_max[i] = std::max(left_max[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
      right_max[i] = std::max(right_max[i + 1], height[i]);
    }
    for (int i = 0; i < n; ++i) {
      volume += (std::min(left_max[i], right_max[i]) - height[i]);
    }

    return volume;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> height1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << s.trap(height1) << std::endl;

  vector<int> height2{4, 2, 0, 3, 2, 5};
  std::cout << s.trap(height2) << std::endl;
  return 0;
}