
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    /**
     * b31 b30   ...     b0
     * ==>
     * b0 b1 ... b31
     */
    uint32_t rev = 0;
    uint8_t bits = sizeof(uint32_t) * 8;
    for (int i = 0; i < bits; i++) {
      rev |= (n & 0x01) << (bits - i - 1);
      n >>= 1;
    }
    return rev;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout<<s.reverseBits(43261596)<<std::endl;
  std::cout<<s.reverseBits(4294967293)<<std::endl;

  return 0;
}
