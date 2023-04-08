//
// Created by 17336 on 2023/4/5.
//

#ifndef HOT100_2_128_H
#define HOT100_2_128_H

#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,vector<int>> dps;
        int len=nums.size(),res=0;
        for (int i=0;i<len;++i) {
            int t=nums[i];
            if(dps.find(t)!=dps.end()) continue;
            if(dps.find(t-1)!=dps.end()&&dps.find(t+1)!=dps.end()) {
                int l=dps[t-1][1],r=dps[t+1][0];
                dps[l][0]=r;
                dps[r][1]=l;
                if(l!=t-1)
                    dps.erase(t-1);
                if(r!=t+1)
                    dps.erase(t+1);
                res= max(res,r-l+1);
            }
            else if(dps.find(t-1)!=dps.end()) {
                int l=dps[t-1][1],r=dps[t-1][0];
                if(t<=r&&t>=l) continue;
                dps[l][0]=t;
                dps[t]=vector<int> {t,l};
                if(l!=t-1)
                    dps.erase(t-1);
                res= max(res,t-l+1);
            }
            else if(dps.find(t+1)!=dps.end()) {
                int r=dps[t+1][0],l=dps[t+1][1];
                if(t<=r&&t>=l) continue;
                dps[r][1]=t;
                dps[t]=vector<int> {r,t};
                if(r!=t+1)
                    dps.erase(t+1);
                res= max(res,r-t+1);
            }
            else {
                dps[t] = vector<int>{t, t};
                res= max(res,1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_128_H
