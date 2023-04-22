//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_494DP_H
#define HOT100_2_494DP_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum=0;
        for (int item:nums){
            sum+=item;
        }
        if((sum+target)%2) return 0;
        int sa=(sum+target)/2;
        if(sa<0) return 0;
        vector<int> dps(sa+1,0);
        dps[0]=1;
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = sa; j >=nums[i] ; --j) {
                dps[j]+=dps[j-nums[i]];
            }
        }
        return dps[sa];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#endif //HOT100_2_494DP_H
