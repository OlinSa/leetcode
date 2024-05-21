#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int num = 0;

    for (unsigned int i = 0; i < s.length(); i++) {
      num += roman_map_[s[i]];
      if (i > 0 && (roman_map_[s[i]] > roman_map_[s[i - 1]])) {
        num -= (2 * roman_map_[s[i - 1]]);
      }
    }

    return num;
  }

 private:
  std::map<char, int> roman_map_ = {
      {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
      {'X', 10},   {'V', 5},   {'I', 1},
  };
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.romanToInt("III") << std::endl;
  std::cout << s.romanToInt("IV") << std::endl;
  std::cout << s.romanToInt("IX") << std::endl;
  std::cout << s.romanToInt("LVIII") << std::endl;
  std::cout << s.romanToInt("MCMXCIV") << std::endl;
  return 0;
}