//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_85_H
#define HOT100_2_85_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int res=0;
        vector<int> nums(n);
        for (int i=0;i<m;++i){
            for (int j=0;j<n;++j) {
                if(matrix[i][j]=='1') nums[j]++;
                else nums[j]=0;
            }
            res= max(res, maxRectangle(nums));
        }
        return res;
    }

    int maxRectangle(vector<int> &nums) {
        nums.push_back(0);
        vector<int> stack,lmins(nums.size(),0);
        int res=0;
        for (int i=0;i<nums.size();++i) {
            while (!stack.empty()&&nums[stack.back()]>nums[i]) {
                int back=stack.back();
                stack.pop_back();
                res= max(res,(i-lmins[back]-1)*nums[back]);
            }
            if(stack.empty()) lmins[i]=-1;
            else lmins[i]=stack.back();
            stack.push_back(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_85_H
