//
// Created by 17336 on 2023/4/13.
//

#ifndef HOT100_2_322_H
#define HOT100_2_322_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dps(amount+1,-1);
        dps[0]=0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if(dps[j]==-1){
                    if(dps[j-coins[i]]!=-1)
                        dps[j]=dps[j-coins[i]]+1;
                }
                else if(dps[j-coins[i]]!=-1) dps[j]= min(dps[j],dps[j-coins[i]]+1);
            }
        }
        return dps[amount]==INT_MAX?-1:dps[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)



#endif //HOT100_2_322_H
