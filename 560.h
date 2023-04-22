//
// Created by 17336 on 2023/4/20.
//

#ifndef HOT100_2_560_H
#define HOT100_2_560_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        int res=0;
        int len=nums.size();
        unordered_map<int,int> pres;
        pres[0]=1;
        for (int i = 0; i < len; ++i) {
            presum+=nums[i];
            if(pres.count(presum-k))
                res+=pres[presum-k];
            pres[presum]++;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_560_H
