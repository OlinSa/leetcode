#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    int ans = 0;
    vector<bool> primes(n, true);
    for (int i = 2; i < n; i++) {
      if (primes[i]) {
        if (isPrime(i)) {
          ++ans;

          // optimization: 将prime i的倍数标记为非质数
          if ((long long)i * i < n) {
            for (int j = i * i; j < n; j += i) {
              primes[j] = false;
            }
          }
        }
      }
    }
    return ans;
  }

 private:
  bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;

  std::cout << s.countPrimes(10) << std::endl;
  std::cout << s.countPrimes(0) << std::endl;
  std::cout << s.countPrimes(5000000) << std::endl;
  return 0;
}