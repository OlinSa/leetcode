#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{};
    }
};

void casesuit(std::vector<int> s, int target) {
    Solution solution;
    std::vector<int> r = solution.twoSum(s, target);
    if (r.size() != 0) {
        std::cout << "r: " << r[0] << "," << r[1] << std::endl;
    }
}

int main() {
    casesuit(std::vector<int>{2, 7, 11, 15}, 9);
    casesuit(std::vector<int>{3, 2, 4}, 6);
    casesuit(std::vector<int>{3, 3}, 6);

    return 0;
}