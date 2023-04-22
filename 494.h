//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_494_H
#define HOT100_2_494_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        unordered_map<int, unordered_map<int, int>> m;
        m[nums.size()][0]=1;
        return findTargetSumWays(nums,target,0,m);
    }

    int findTargetSumWays(vector<int> &nums, long long target, int from, unordered_map<int, unordered_map<int, int>> &m) {
        if(m.count(from) && m[from].count(target)) return m[from][target];
        if(from>=nums.size()) return 0;
        int len=nums.size();
        int res=0;
        res= findTargetSumWays(nums,target-nums[from],from+1,m);
        res+=findTargetSumWays(nums,target+nums[from],from+1,m);
        m[from][target]=res;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_494_H
