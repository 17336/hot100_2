//
// Created by 17336 on 2023/4/9.
//

#ifndef HOT100_2_238_H
#define HOT100_2_238_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int len=nums.size(),t=1;
        for (int i = 0; i < len; ++i) {
            res[i]=t;
            t*=nums[i];
        }
        t=1;
        for (int i = len-1; i >= 0 ; --i) {
            res[i]*=t;
            t*=nums[i];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_238_H
