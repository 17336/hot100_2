//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_46_H
#define HOT100_2_46_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(),0),path;
        vector<vector<int>> res;
        backtrace(nums,res,path,visited);
        return res;
    }

    void backtrace(vector<int> &nums,vector<vector<int>> &res, vector<int> &path, vector<int> &visted) {
        if(nums.size()==path.size()) {
            res.push_back(path);
            return;
        }
        for (int i=0;i<nums.size();++i) {
            if(!visted[i]) {
                path.push_back(nums[i]);
                visted[i]=1;
                backtrace(nums,res,path,visted);
                visted[i]=0;
                path.pop_back();
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_46_H
