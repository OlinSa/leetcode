#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        std::map<int, int> mark;
        for (auto &e: nums) {
            mark[e] += 1;
        }

        for (int i = 1;; i++) {
            if (mark[i] == 0) {
                return i;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> case1{1, 2, 0};
    std::cout << s.firstMissingPositive(case1) << std::endl;
    vector<int> case2{3, 4, -1, 1};
    std::cout << s.firstMissingPositive(case2) << std::endl;
    vector<int> case3{7, 8, 9, 11, 12};
    std::cout << s.firstMissingPositive(case3) << std::endl;
    return 0;
}