//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_283_H
#define HOT100_2_283_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            if(nums[i]==0) {
                if(j<=i) j=i+1;
                while (j<len&&nums[j]==0) ++j;
                if(j==len) return;
                swap(nums[i],nums[j]);
            }
        }
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_283_H
