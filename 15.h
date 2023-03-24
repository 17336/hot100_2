//
// Created by ByteDance on 2023/3/21.
//

#ifndef HOT100_2_15_H
#define HOT100_2_15_H

#include <vector>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 借鉴了两数之和哈希表的思想，结果O(n^2)超时了
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end(),less<int>());
        vector<vector<int>> res;
        for (int i = 0; i < len-2; ++i) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            unordered_set<int> m;
            for (int j = i+1; j < len; ++j) {
                if(m.find(target-nums[j])!=m.end() &&(res.empty() || res.back()!= vector<int> {nums[i],target-nums[j],nums[j]})) {
                    res.push_back({nums[i],target-nums[j],nums[j]});
                }
                m.emplace(nums[j]);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_15_H
