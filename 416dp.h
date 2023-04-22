//
// Created by 17336 on 2023/4/17.
//

#ifndef HOT100_2_416DP_H
#define HOT100_2_416DP_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for (int i = 0; i < n; ++i) {
            sum+=nums[i];
        }
        if(sum%2) return false;
        int target=sum/2;
        vector<int> dps(target+1,0);
        dps[0]=1;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j>=nums[i]; --j) {
                if(dps[j]) continue;
                dps[j]=dps[j-nums[i]];
            }
        }
        return dps[target];
    }
};

#endif //HOT100_2_416DP_H
