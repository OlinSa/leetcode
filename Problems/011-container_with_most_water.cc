#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int area = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            area = std::min(height[l], height[r]);
            max_area = std::max(max_area, area * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> height1{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(height1) << std::endl;

    vector<int> height2{1, 1};
    std::cout << s.maxArea(height2) << std::endl;
    return 0;
}