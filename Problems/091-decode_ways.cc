#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// "1" -> 'A'
// "26" -> 'Z'

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();

    vector<int> f(n + 1);
    f[0] = 1;
    /**
     * f(1) = 1   i = 1
     * f(i) = f(i-1)  s[i] != 0
     * f(i) = f(i-2)  s[i-1] != 0 && s[i-1] * 10 + s[i] < 26
     *
     * */
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] != '0') {
        f[i] += f[i - 1];
      }
      if (i > 1 && s[i - 2] != '0' &&
          ((((s[i - 2] - '0') * 10) + (s[i - 1] - '0') <= 26))) {
        f[i] += f[i - 2];
      }
    }
    return f[n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.numDecodings("12") << std::endl;
  std::cout << s.numDecodings("226") << std::endl;
  std::cout << s.numDecodings("06") << std::endl;
  std::cout << s.numDecodings("27") << std::endl;

  return 0;
}