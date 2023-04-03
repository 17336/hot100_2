//
// Created by 17336 on 2023/3/31.
//

#ifndef HOT100_2_31_H
#define HOT100_2_31_H

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int max = -1, i = nums.size() - 1;
        while (i >= 0) {
            if (max >= 0 && nums[i] < nums[max]) {
                for (int j=i+1;j<nums.size();++j) {
                    if(nums[j] >nums[i]) max=j;
                }
                swap(nums[i], nums[max]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
            if (max < 0 || nums[i] > nums[max]) max = i;
            --i;
        }
        sort(nums.begin(),nums.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_31_H
