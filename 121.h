//
// Created by 17336 on 2023/4/4.
//

#ifndef HOT100_2_121_H
#define HOT100_2_121_H

#include <vector>
#include <climits>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lmin=INT_MAX,res=0,len=prices.size();
        for (int i=0;i<len;++i) {
            if(lmin<prices[i]) res= max(res,prices[i]-lmin);
            lmin= min(lmin,prices[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_121_H
