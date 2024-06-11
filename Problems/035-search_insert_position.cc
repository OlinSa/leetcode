#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mid;
        int ans = n;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums1{1, 3, 5, 6};
    std::cout << s.searchInsert(nums1, 5) << std::endl;
    std::cout << s.searchInsert(nums1, 2) << std::endl;
    std::cout << s.searchInsert(nums1, 7) << std::endl;
    vector<int> nums2{1};
    std::cout << s.searchInsert(nums2, 1) << std::endl;
    return 0;
}