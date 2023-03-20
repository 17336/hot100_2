//
// Created by ByteDance on 2023/3/20.
//

#ifndef HOT100_2_4_H
#define HOT100_2_4_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int len1;
    int len2;
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        len1 = nums1.size();
        len2 = nums2.size();
        if ((len1 + len2) % 2) return findK(nums1, nums2, 0, 0, (len1 + len2) / 2+1);
        return (findK(nums1, nums2, 0, 0, (len1 + len2) / 2) + findK(nums1, nums2, 0, 0, (len1 + len2) / 2+1)) / 2.0;
    }

    int64_t findK(vector<int> &nums1, vector<int> &nums2, int i1, int i2, int k) {
        if (i1 >= len1) return nums2[i2 + k-1];
        if (i2 >= len2) return nums1[i1 + k-1];
        if (k == 1) return min(nums1[i1], nums2[i2]);
        int k1 = (i1 + k / 2-1) < len1 ? nums1[i1 + k / 2-1] : INT32_MAX;
        int k2 = (i2 + k / 2-1) < len2 ? nums2[i2 + k / 2-1] : INT32_MAX;
        if (k1 <= k2) {
            return findK(nums1, nums2, i1 + k / 2, i2, k - k / 2);
        } else {
            return findK(nums1, nums2, i1, i2 + k / 2, k - k / 2);
        }
    }

    // error thought
    double findMedian(vector<int> &nums1, vector<int> &nums2, int i1, int j1, int i2, int j2) {
        if ((len1 + len2) % 2) {

        }

        int m1 = (i1 + j1) / 2, m2 = (i2 + j2) / 2;
        if (nums1[m1] <= nums2[m2]) {
            i1 = m1 + 1;
            j2 = m2 - 1;
        } else if (nums1[m1] > nums2[m2]) {
            j1 = m1 - 1;
            i2 = m2 + 1;
        }
        return findMedian(nums1, nums2, i1, j1, i2, j2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_4_H
