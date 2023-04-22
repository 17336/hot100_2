//
// Created by 17336 on 2023/4/6.
//

#ifndef HOT100_2_152_H
#define HOT100_2_152_H

#include <vector>
#include <climits>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lmax=1,lmin=1;
        int len=nums.size(),res=INT_MIN;
        for (int i=0;i<len;++i) {
            int tmax=nums[i],tmin=nums[i];
            tmax= max(tmax, max(lmin*tmax,lmax*tmax));
            tmin= min(tmin, min(lmin*tmin,lmax*tmin));
            lmax=tmax;
            lmin=tmin;
            res= max(res,tmax);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_152_H
