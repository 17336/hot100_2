//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_198_H
#define HOT100_2_198_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        int l0=0,l1=0;
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            int t= max(l0+nums[i],l1);
            l0=l1;
            l1=t;
        }
        return l1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_198_H
