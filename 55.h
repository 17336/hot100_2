//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_55_H
#define HOT100_2_55_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 维护一个能跳到的最右位置rmax，当遍历位置不在rmax内，说明跳跃失败
        int rmax=0,len=nums.size();
        for (int i=0;i<len;++i) {
            if(i>rmax) return false;
            rmax= max(rmax,i+nums[i]);
            if(rmax>=len-1) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_55_H
