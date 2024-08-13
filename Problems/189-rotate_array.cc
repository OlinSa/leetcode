#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    int count = gcd(k, n);
    for (int i = 0; i < count; ++i) {
      int current = i;
      int prev = nums[i];

      do {
        int next = (current + k) % n;
        swap(nums[next], prev);
        current = next;
      } while (i != current);
    }
  }

 private:
  int gcd(int a, int b) {
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
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
  vector<int> nums1{1, 2, 3, 4, 5, 6, 7};
  s.rotate(nums1, 3);
  DumpVector(nums1);

  vector<int> nums2{-1, -100, 3, 99};
  s.rotate(nums2, 2);
  DumpVector(nums2);

  return 0;
}