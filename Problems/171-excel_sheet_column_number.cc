#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    /**
     *  A -> 1
     *  B -> 2
     *  C -> 3
     *  ...
     *  Z -> 26
     *  AA -> 27
     *  AB -> 28  (a[i] - 'A' + 1) * 26 ^ i -1 + a[i-1]
     *  ...
     */
    std::reverse(columnTitle.begin(), columnTitle.end());
    int number = 0;
    int n = columnTitle.size();

    long long multiple = 1;
    for (int i = 0; i < n; ++i) {
      number += (columnTitle[i] - 'A' + 1) * multiple;
      multiple *= 26;
    }

    return number;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << s.titleToNumber("A") << std::endl;
  std::cout << s.titleToNumber("AB") << std::endl;
  std::cout << s.titleToNumber("ZY") << std::endl;

  return 0;
}