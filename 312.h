//
// Created by 17336 on 2023/4/12.
//

#ifndef HOT100_2_312_H
#define HOT100_2_312_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int len=nums.size();
        vector<vector<int>> dps(len,vector<int> (len,0));
        for (int i = 1; i < len-1; ++i) {
            for (int j = 1; j <= i; ++j) {
                if(i==j) dps[j][i]=nums[i]*nums[i-1]*nums[i+1];
                else {
                    int t=0;
                    for (int k = j; k <= i; ++k) {
                        t= max(nums[k]*nums[j-1]*nums[i+1]+dps[j][k-1]+dps[k+1][i],t);
                    }
                    dps[j][i]=t;
                }
            }
        }
        return dps[1][len-2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_312_H
