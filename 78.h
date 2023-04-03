//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_78_H
#define HOT100_2_78_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrace(path,res,nums,0);
        return res;
    }

    void backtrace(vector<int> &path,vector<vector<int>> &res,vector<int> &nums,int begin) {
        res.push_back(path);
        for (int i=begin;i<nums.size();++i) {
            path.push_back(nums[i]);
            backtrace(path,res,nums,i+1);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_78_H
