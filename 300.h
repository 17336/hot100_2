//
// Created by 17336 on 2023/4/12.
//

#ifndef HOT100_2_300_H
#define HOT100_2_300_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(),res=0;
        vector<int> dps(len,0);
        for (int i = 0; i < len; ++i) {
            int temp=1;
            for (int j = 0; j < i; ++j) {
                if(nums[j]<nums[i]) temp= max(temp,dps[j]+1);
            }
            dps[i]=temp;
            res= max(res,temp);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_300_H
