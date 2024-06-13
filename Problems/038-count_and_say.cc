#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; i++) {
            string curr = "";
            int start = 0;
            int pos = 0;
            while (pos < prev.size()) {
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos++;
                }
                curr += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = curr;
        }
        return prev;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    std::cout << s.countAndSay(4) << std::endl;
    return 0;
}