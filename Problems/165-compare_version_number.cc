
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    std::vector<int> token1 = splitVersion(version1, '.');
    std::vector<int> token2 = splitVersion(version2, '.');
    int max_len = std::max(token1.size(), token2.size());
    for (int i = 0; i < max_len; i++) {
      int v1 = i >= token1.size() ? 0 : token1[i];
      int v2 = i >= token2.size() ? 0 : token2[i];
      if (v1 == v2) continue;
      return v1 < v2 ? -1 : 1;
    }
    return 0;
  }

  std::vector<int> splitVersion(const std::string& input, char delimiter) {
    std::vector<int> tokens;
    std::string token;
    std::istringstream tokenStream(input);

    // Split the input string by the delimiter
    while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(std::stoi(token));
    }

    return tokens;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.compareVersion("1.2", "1.10") << std::endl;
  std::cout << s.compareVersion("1.01", "1.001") << std::endl;
  std::cout << s.compareVersion("1.0", "1.0.0") << std::endl;
  return 0;
}