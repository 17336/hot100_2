//
// Created by ByteDance on 2023/3/17.
//

#ifndef HOT100_2_1BEST_H
#define HOT100_2_1BEST_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        unordered_map<int,int> m;
        for (int i = 0; i < len; ++i) {
            if(m.find(target-nums[i])!=m.end()) return {i,m[target-nums[i]]};
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};

#endif //HOT100_2_1BEST_H
