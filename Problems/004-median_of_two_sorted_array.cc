#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = (nums1.size() + nums2.size());
        int odd = n % 2;
        int num = 0;
        // It is necessary to distinguish between situations where nums1 and nums2 are both empty
        // even:median_r = media_l + 1, odd: median_r = median_l
        int median_l = n / 2 - (n == 0 ? 0 : (odd ? 0 : 1));
        int median_r = median_l + (n == 0 ? 0 : odd ? 0 : 1);

        std::cout << "median:" << median_l << "," << median_r << std::endl;

        std::vector<int>::iterator it1 = nums1.begin();
        std::vector<int>::iterator it2 = nums2.begin();
        for (int i = 0; i <= median_r; i++) {
            if (it1 == nums1.end()) {
                if (i == median_l) {
                    num += *it2;
                }
                if (i == median_r) {
                    num += *it2;
                }
                it2++;
                continue;
            }
            if (it2 == nums2.end()) {
                if (i == median_l) {
                    num += *it1;
                }
                if (i == median_r) {
                    num += *it1;
                }
                it1++;
                continue;
            }
            if (*it1 < *it2) {
                if (i == median_l) {
                    num += *it1;
                }
                if (i == median_r) {
                    num += *it1;
                }
                it1++;
            } else {
                if (i == median_l) {
                    num += *it2;
                }
                if (i == median_r) {
                    num += *it2;
                }
                it2++;
            }
        }

        return (double) num / 2;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    std::vector<int> n1{1, 3};
    std::vector<int> n2{2};
    std::cout << solution.findMedianSortedArrays(n1, n2) << std::endl;

    std::vector<int> n3{1, 2};
    std::vector<int> n4{3, 4};
    std::cout << solution.findMedianSortedArrays(n3, n4) << std::endl;

    std::vector<int> n5{1};
    std::vector<int> n6{};
    std::cout << solution.findMedianSortedArrays(n5, n6) << std::endl;
    return 0;
}