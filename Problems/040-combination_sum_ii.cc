#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> out;
        vector<int> combine;
        sort(candidates.begin(), candidates.end());
        dfs(out, candidates, combine, target, 0);
        return out;
    }

private:
    void dfs(vector<vector<int>> &out, vector<int> &candidates, vector<int> &combine, int target, int idx) {
        if (target == 0) {
            out.push_back(combine);
            return;
        }
        if (idx > candidates.size()) {
            return;
        }
        for (int i = idx; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            combine.push_back(candidates[i]);
            dfs(out, candidates, combine, target - candidates[i], i + 1);
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
    vector<int> case1{10, 1, 2, 7, 6, 1, 5};
    DumpVector(s.combinationSum2(case1, 8));
    vector<int> case2{2, 5, 2, 1, 2};
    DumpVector(s.combinationSum2(case2, 5));
    return 0;
}