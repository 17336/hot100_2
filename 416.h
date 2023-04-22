//
// Created by 17336 on 2023/4/17.
//

#ifndef HOT100_2_416_H
#define HOT100_2_416_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i:nums) {
            sum+=i;
        }
        if(sum%2) return false;
        vector<int> visited(nums.size(),0);
        return canPartition(nums,sum/2,visited);
    }

    bool canPartition(unordered_map<int,int> &nums,int target,vector<int> &visited) {
        if(target==0) return true;
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            if(visited[i]==0&&nums[i]<=target) {
                visited[i]=1;
                if(canPartition(nums,target-nums[i],visited)) return true;
                visited[i]=0;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_416_H
