#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    /**
    * use arr[i]=j to indicate that
    * the regular expression is met from subscrit of string i to j
    *
    * traverse all arrays, find the union of all data and cover all
    subscripts
    * to match the regular expression dp[i][j] 表示s前i匹配上s前p字符
    *
    *
    * dp[i][j] = (s[i] == p[j]) ^ dp[i-1][j-1]， alphabet
    * dp[i][j] = dp[i-1][j-1], ?
    * dp[i][j] = dp[i][j-1] | dp[i-1][j]，*
    *
    * ==>
    * 1. ？ | s[i] == p[j] ：dp[i][j] = dp[i-1][j-1]
    * 2. *                 : dp[i][j-1] | dp[i-1][j]
    * 3. other             : false
    *
    * 场景:
    * 1. s及p均为空：dp[0][0] = true;
    * 2. p为空: dp[i][0] = false
    * 3. *开头: dp[0][j] = true
    *
    */
    int m = s.size(), n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
    dp[0][0] = true;

    // 这里处理*开头的pattern的场景dp[0][1]
    for (int j = 1; j <= n; j++) {
      if (p[j - 1] == '*') {
        dp[0][j] = true;
      } else {
        break;
      }
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
        } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << s.isMatch("adceb", "*a*b") << std::endl;
  std::cout << s.isMatch("aa", "a") << std::endl;
  std::cout << s.isMatch("aa", "aa") << std::endl;
  std::cout << s.isMatch("aa", "a?") << std::endl;
  std::cout << s.isMatch("aa", "*") << std::endl;
  std::cout << s.isMatch("aa", "?") << std::endl;
  std::cout << s.isMatch("aa", "??") << std::endl;
  std::cout << s.isMatch("cb", "7a") << std::endl;

  return 0;
}