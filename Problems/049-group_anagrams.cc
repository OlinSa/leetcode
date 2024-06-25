#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> output;
    std::map<string, vector<string>> str_hash_map;

    for (int i = 0; i < strs.size(); i++) {
      string temp = strs[i];
      sort(temp.begin(), temp.end());
      str_hash_map[temp].push_back(strs[i]);
    }
    for (auto anagrams : str_hash_map) {
      output.push_back(anagrams.second);
    }
    return output;
  }
};

void DumpVector(std::vector<std::vector<string>> source) {
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

int main(int argc, char* argv[]) {
  Solution s;
  vector<string> str1{"eat", "tea", "tan", "ate", "nat", "bat"};
  DumpVector(s.groupAnagrams(str1));
  vector<string> str2{""};
  DumpVector(s.groupAnagrams(str2));
  vector<string> str3{"a"};
  DumpVector(s.groupAnagrams(str3));

  return 0;
}