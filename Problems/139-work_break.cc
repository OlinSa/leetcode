#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // dp[i] = s[0 .. i] in wordDict
    // dp[i]= dp[j] && check(s[j..i-1])  j=[0,i)
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && std::find(wordDict.begin(), wordDict.end(),
                               s.substr(j, i - j)) != wordDict.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<string> dict1{"leet", "code"};
  std::cout << s.wordBreak("leetcode", dict1) << std::endl;

  vector<string> dict2{"apple", "pen"};
  std::cout << s.wordBreak("applepenapple", dict2) << std::endl;

  vector<string> dict3{"cats", "dog", "sand", "and", "cat"};
  std::cout << s.wordBreak("catsandog", dict3) << std::endl;
  return 0;
}
