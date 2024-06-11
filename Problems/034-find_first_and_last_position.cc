#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        // 寻找第一个>=target的索引
        int left = binarySearch(nums, target, true);
        // 寻找第一个大于target的坐标
        int right = binarySearch(nums, target, false) - 1;
        if (left <= right && left >= 0) {
            return vector<int>{left, right};
        }
        return vector<int>{-1, -1};
    }

private:
    int binarySearch(const vector<int> &nums, int target, bool low) {
        int n = nums.size();
        int ans = n;
        int l = 0, r = nums.size() - 1;
        int mid;

        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > target || (low && (nums[mid] >= target))) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums1{5, 7, 7, 8, 8, 10};
    vector<int> result1 = s.searchRange(nums1, 8);
    std::cout << result1[0] << "," << result1[1] << std::endl;
    vector<int> nums2{5, 7, 8, 8, 10};
    vector<int> result2 = s.searchRange(nums2, 6);
    std::cout << result2[0] << "," << result2[1] << std::endl;
    vector<int> nums3{};
    vector<int> result3 = s.searchRange(nums3, 0);
    std::cout << result3[0] << "," << result3[1] << std::endl;
    vector<int> nums4{1};
    vector<int> result4 = s.searchRange(nums4, 1);
    std::cout << result4[0] << "," << result4[1] << std::endl;
    return 0;
}