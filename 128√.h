//
// Created by 17336 on 2023/4/5.
//

#ifndef HOT100_2_128_H
#define HOT100_2_128_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> dps;
        int len = nums.size(), res = 0;
        for (int i = 0; i < len; ++i) {
            int t = nums[i];
            if (dps.find(t) == dps.end()) {
                int left = dps.find(t - 1) == dps.end() ? 0 : dps[t - 1], right =
                        dps.find(t + 1) == dps.end() ? 0 : dps[t + 1];
                int curlen=left+right+1;
                dps[t]=curlen;
                if(left>0) dps[t-left]=curlen;
                if(right>0) dps[t+right] =curlen;
                res= max(curlen,res);
            }
        }
        return res;
    }
};

#endif //HOT100_2_128_H
