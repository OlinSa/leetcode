
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int hammingWeight(int n) {
    int weight = 0;
    while (n > 0) {
      if (n & 0x01) {
        weight++;
      }
      n >>= 1;
    }
    return weight;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.hammingWeight(11) << std::endl;
  std::cout << s.hammingWeight(128) << std::endl;

  return 0;
}