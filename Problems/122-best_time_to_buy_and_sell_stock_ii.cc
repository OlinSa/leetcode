#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      int profit = prices[i] - prices[i - 1];
      if (profit > 0) {
        ans += profit;
      }
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> prices1{7, 1, 5, 3, 6, 4};
  std::cout << s.maxProfit(prices1) << std::endl;
  vector<int> prices2{7, 6, 4, 3, 1};
  std::cout << s.maxProfit(prices2) << std::endl;
  return 0;
}