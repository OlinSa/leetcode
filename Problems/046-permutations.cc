#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> output;
        vis.resize(nums.size(), 0);
        dfs(output, nums, 0);
        return output;
    }

private:
    void dfs(vector<vector<int>> &output, vector<int> &nums, int idx) {
        if (idx >= nums.size()) {
            output.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 暴力深度遍历，使用vis标记已填入的元素
            if (vis[i]) continue;
            vis[i]++;
            path.push_back(nums[i]);
            dfs(output, nums, idx + 1);
            vis[i]--;
            path.pop_back();
        }
    }

private:
    vector<int> vis;
    vector<int> path;
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
    std::vector<int> case1{1, 2, 3, 4};
    DumpVector(s.permute(case1));
    std::vector<int> case2{0, 1};
    DumpVector(s.permute(case2));
    std::vector<int> case3{1};
    DumpVector(s.permute(case3));
    return 0;
}