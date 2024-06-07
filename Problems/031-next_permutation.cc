#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        /**
         * 4,5,2,6,3,1 ==> 4,5,3,6,2,1
         * 1. 从左侧寻找一个较小数， 右侧寻找较大数
         * 2. 较小数尽量靠右， 较大数尽可能小
         * 3. 交换完成后， 较大数右侧需要升序确保幅度尽量的小
         *
         * 从右往左搜索， (i,i+1),满足a[i] < a[i+1], 这样「较小数」即为 a[i]。此时 [i+1,n)必然是下降序列
         * 如果找到了顺序对，那么在区间 [i+1,n)中从后向前查找第一个元素 j 满足 a[i]<a[j]。这样「较大数」即为 a[j]。
         * 交换 a[i]与 a[j]，此时可以证明区间 [i+1,n)必为降序。我们可以直接使用双指针反转区间 [i+1,n)使其变为升序，而无需对该区间进行排序。
         */
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

void dumpVector(const vector<int> &nums) {
    std::cout << "{";
    for (auto n: nums) {
        std::cout << n << ",";
    }
    std::cout << "}" << std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    std::vector<int> case1{1, 2, 3};
    s.nextPermutation(case1);
    dumpVector(case1);
    std::vector<int> case2{3, 2, 1};
    s.nextPermutation(case2);
    dumpVector(case2);
    std::vector<int> case3{1, 1, 5};
    s.nextPermutation(case3);
    dumpVector(case3);
    return 0;
}