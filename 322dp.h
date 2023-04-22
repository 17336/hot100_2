//
// Created by 17336 on 2023/4/13.
//

#ifndef HOT100_2_322DP_H
#define HOT100_2_322DP_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int len=coins.size();
        sort(coins.begin(),coins.end());
        vector<int> dps(amount+1,0);
        for (int i = 1; i <= amount; ++i) {
            int j=0;
            int t=INT_MAX;
            while (j<len&&coins[j]<=i) {
                if(coins[j]==i) {
                    t=1;
                }
                if(dps[i-coins[j]]>0)
                    t= min(t,dps[i-coins[j]]+1);
                ++j;
            }
            dps[i]=t==INT_MAX?-1:t;
        }
        return dps.back();
    }
};
#endif //HOT100_2_322DP_H
