//
// Created by ByteDance on 2023/3/22.
//

#ifndef HOT100_2_15BEST_H
#define HOT100_2_15BEST_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        if(nums[0]>0 || nums.back() <0) return {};
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=len-1,target=-nums[i];
            while (l<r) {
                if(l>i+1&&nums[l]==nums[l-1]) {
                    ++l;
                    continue;
                }
                if(r<len-1 && nums[r]==nums[r+1]) {
                    --r;
                    continue;
                }
                int sum =nums[l]+nums[r];
                if(sum<target) ++l;
                else if (sum >target) --r;
                else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    ++l;
                    --r;
                }
            }
        }
        return res;
    }
};

#endif //HOT100_2_15BEST_H
