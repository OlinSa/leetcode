#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    /**
     * A = 1
     *
     * Z = 26
     * AA = 27
     *
     */

    std::string s;
    int z;
    while (columnNumber > 0) {
      z = (columnNumber - 1) % 26 + 1;
      s += (z - 1 + 'A');
      columnNumber = (columnNumber - z) / 26;
    }
    std::reverse(s.begin(), s.end());
    return s;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << s.convertToTitle(1) << std::endl;
  std::cout << s.convertToTitle(28) << std::endl;
  std::cout << s.convertToTitle(701) << std::endl;
  std::cout << s.convertToTitle(2147483647) << std::endl;

  return 0;
}