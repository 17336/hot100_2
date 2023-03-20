//
// Created by ByteDance on 2023/3/15.
//

#ifndef HOT100_2_1_H
#define HOT100_2_1_H

#include <vector>
#include <algorithm>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,len=nums.size(),j=len-1;
        vector<vector<int>> nums_(nums.size());
        for (int k = 0; k < len; ++k) {
            nums_[k].push_back(nums[k]);
            nums_[k].push_back(k);
        }
        // notice: sort func usage
        struct {
            bool operator()(vector<int> &a, vector<int> &b) {
                return a[0]<b[0];
            }
        } s;
        sort(nums_.begin(),nums_.end(),less_equal<int>());
        while (i<j){
            int sum = nums_[i][0]+nums_[j][0];
            if(sum==target) return {nums_[i][1],nums_[j][1]};
            if (sum>target) --j;
            else ++i;
        }
        return {-1,-1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)



#endif //HOT100_2_1_H
