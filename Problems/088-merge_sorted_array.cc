
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // This problem is an ordered array, and there is no need to consider the
    // additional sorting required for the internal array.
    int last_pos = m + n - 1;
    int p1 = m - 1, p2 = n - 1;
    int cur;
    while ((p1 >= 0 || p2 >= 0)) {
      if (p1 == -1) {
        cur = nums2[p2--];
      } else if (p2 == -1) {
        cur = nums1[p1--];
      } else if (nums1[p1] < nums2[p2]) {
        cur = nums2[p2--];
      } else {
        cur = nums1[p1--];
      }
      nums1[last_pos--] = cur;
    }

    return;
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
  vector<int> nums11 = {1, 2, 3, 0, 0, 0}, nums12 = {2, 5, 6};
  s.merge(nums11, 3, nums12, 3);
  dumpVector(nums11);
  vector<int> nums21 = {1}, nums22 = {};
  s.merge(nums21, 1, nums22, 0);
  dumpVector(nums21);
  vector<int> nums31 = {0}, nums32 = {1};
  s.merge(nums31, 0, nums32, 1);
  dumpVector(nums31);

  return 0;
}