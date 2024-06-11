#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;

        int l = 0, r = n - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> num1{4, 5, 6, 7, 0, 1, 2};
    std::cout << s.search(num1, 0) << std::endl;
    std::cout << s.search(num1, 3) << std::endl;
    vector<int> num2{1};
    std::cout << s.search(num2, 0) << std::endl;
    vector<int> num3{5,1,2,3,4};
    std::cout << s.search(num3, 1) << std::endl;
    vector<int> num4{5, 1, 3};
    std::cout << s.search(num4, 5) << std::endl;
    return 0;
}