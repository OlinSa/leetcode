#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define SEGMENT_MAX 4

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> output;
    segments_.reserve(4);

    dfs(output, s, 0, 0);
    return output;
  }

 private:
  void dfs(vector<string>& output, const string& s, unsigned int seg_id,
           unsigned int seg_begin) {
    // 1. All segments has been searched and the search has been converted
    if (seg_id == SEGMENT_MAX) {
      if (seg_begin == s.size()) {
        string ip;
        for (int i = 0; i < SEGMENT_MAX; ++i) {
          ip += to_string(segments_[i]);
          if (i != SEGMENT_MAX - 1) {
            ip += ".";
          }
        }
        output.push_back(ip);
      }
      return;
    }
    // 2. return immediately when the end of the string has been reached
    if (seg_begin == s.size()) {
      return;
    }

    // 3. the segment is 0 only when the seg_begin is 0
    if (s[seg_begin] == '0') {
      segments_[seg_id] = 0;
      dfs(output, s, seg_id + 1, seg_begin + 1);
      return;
    }

    // 4. enumerate every possible combination
    unsigned int addr = 0;
    for (unsigned int i = seg_begin; i < s.size(); ++i) {
      addr = s[i] - '0' + addr * 10;
      if (addr <= 0xFF) {
        segments_[seg_id] = addr;
        dfs(output, s, seg_id + 1, i + 1);
      } else {
        break;
      }
    }
  }
  std::vector<int> segments_;
};

void DumpVector(std::vector<string> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << "[";
    std::cout << it1 << ",";
    std::cout << "]";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  DumpVector(s.restoreIpAddresses("25525511135"));
  DumpVector(s.restoreIpAddresses("0000"));
  DumpVector(s.restoreIpAddresses("101023"));

  return 0;
}