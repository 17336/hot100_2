//
// Created by 17336 on 2023/4/12.
//

#ifndef HOT100_2_309_H
#define HOT100_2_309_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        vector<int> dps(len,0);
        for (int i = 0; i < len; ++i) {
            int m=i>0?dps[i-1]:0;
            for (int j = 0; j < i; ++j) {
                if(prices[j]<prices[i])
                    m= max(m, prices[i]-prices[j]+(j>=2?dps[j-2]:0));
            }
            dps[i]=m;
        }
        return dps.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_309_H
