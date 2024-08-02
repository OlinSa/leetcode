#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_prices = INT32_MAX;
    int max_prices = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i) {
      if (min_prices > prices[i]) {
        min_prices = prices[i];
      } else if (max_prices < prices[i] - min_prices) {
        max_prices = prices[i] - min_prices;
      }
    }

    return max_prices;
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