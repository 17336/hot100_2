//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_53_H
#define HOT100_2_53_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size(),res=nums[0];
        vector<int> maxs(len,0);
        maxs[0]=nums[0];
        for (int i=1;i<nums.size();++i) {
            if(maxs[i-1]>0) maxs[i]=maxs[i-1]+nums[i];
            else maxs[i]=nums[i];
            res= max(res,maxs[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_53_H
