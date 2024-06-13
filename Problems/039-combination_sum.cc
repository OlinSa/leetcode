#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> out;
        vector<int> combine;
        dfs(out, combine, candidates, target, 0);
        return out;
    }

private:
    void dfs(vector<vector<int>> &out, vector<int> &combine, vector<int> &candidates, int target, int idx) {
        if (target == 0) {
            out.push_back(combine);
            return;
        }
        if (idx == candidates.size()) {
            return;
        }
        dfs(out, combine, candidates, target, idx + 1);
        if (target - candidates[idx] >= 0) {
            combine.push_back(candidates[idx]);
            dfs(out, combine, candidates, target - candidates[idx], idx);
            combine.pop_back();
        }
    }
};

void DumpVector(std::vector<std::vector<int>> source) {
    std::cout << "[";
    for (auto it1: source) {
        std::cout << "[";
        for (auto it2: it1) {
            std::cout << it2 << ",";
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> case1{2, 3, 6, 7};
    DumpVector(s.combinationSum(case1, 7));
    vector<int> case2{2, 3, 5};
    DumpVector(s.combinationSum(case2, 8));
    vector<int> case3{2};
    DumpVector(s.combinationSum(case3, 1));

    return 0;
}