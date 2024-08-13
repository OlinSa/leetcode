
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> output;
    std::map<string, int> str_freq;
    int sub_len = 10;

    int i = 0, j = i + sub_len - 1;

    while (j < s.size()) {
      ++str_freq[s.substr(i, j - i + 1)];

      i++;
      j++;
    }

    auto it = str_freq.begin();
    while (it != str_freq.end()) {
      if (it->second > 1) {
        output.push_back(it->first);
      }
      it++;
    }
    return output;
  }
};

void DumpVector(std::vector<string> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << it1 << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  DumpVector(s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
  DumpVector(s.findRepeatedDnaSequences("AAAAAAAAAAAAA"));

  return 0;
}