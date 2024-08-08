#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // vector<int> twoSum(vector<int>& numbers, int target) {
  //   int n = numbers.size();
  //   for (int i = 0; i < n - 1; i++) {
  //     int numbers1 = numbers[i];
  //     for (int j = i + 1; j < n; j++) {
  //       int numbers2 = numbers[j];
  //       if ((numbers1 + numbers2) == target) {
  //         return vector<int>{i + 1, j + 1};
  //       }
  //       // numbers是非递减序列， 当前序列 > target， 则无需继续往后遍历
  //       if ((numbers1 + numbers2) > target) {
  //         break;
  //       }
  //     }
  //   }
  //   return vector<int>{-1, -1};
  // }

  vector<int> twoSum(vector<int>& numbers, int target) {
    // 暴力法超时， 则改用二分遍历
    int n = numbers.size();
    int mid;
    for (int i = 0; i < n - 1; i++) {
      int numbers1 = numbers[i];
      int l = i + 1, r = n - 1;
      while (l <= r) {
        mid = (l + r) / 2;
        int numbers2 = numbers[mid];
        int d = numbers1 + numbers2 - target;

        if (d > 0) {
          r = mid - 1;
        } else if (d < 0) {
          l = mid + 1;
        } else {
          return vector<int>{i + 1, mid + 1};
        }
      }
    }
    return vector<int>{-1, -1};
  }
};

void DumpVector(std::vector<int> source) {
  std::cout << "[";
  for (auto it : source) {
    std::cout << it << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> numbers1{2, 7, 11, 15};
  DumpVector(s.twoSum(numbers1, 9));

  vector<int> numbers2{2, 3, 4};
  DumpVector(s.twoSum(numbers2, 6));

  vector<int> numbers3{-1, 0};
  DumpVector(s.twoSum(numbers3, -1));
}