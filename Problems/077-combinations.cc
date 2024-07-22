#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> output;
    temp.reserve(2);

    /**
     * 1 2 3 4
     */

    dfs(output, n, k, 1);

    return output;
  }

 private:
  void dfs(vector<vector<int>> &output, int n, int k, int cur) {
    if (temp.size() == k) {
      output.push_back(temp);
      return;
    }

    for (int i = cur; i <= n; i++) {
      if (temp.size() == k) continue;
      if (!temp.empty() && i <= temp.back()) continue;
      temp.push_back(i);
      dfs(output, n, k, cur + 1);
      temp.pop_back();
    }
  }
  vector<int> temp;
};

void DumpVector(std::vector<std::vector<int>> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << "[";
    for (auto it2 : it1) {
      std::cout << it2 << ",";
    }
    std::cout << "]";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  DumpVector(s.combine(3, 2));
  DumpVector(s.combine(4, 2));
  DumpVector(s.combine(1, 1));
  return 0;
}