//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_221_H
#define HOT100_2_221_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int res=0;
        vector<int> nums(n+1,0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j]!='0') nums[j]+=1;
                else nums[j]=0;
            }
            res= max(res, maximalSquare(nums));
        }
        return res;
    }

    int maximalSquare(vector<int> &nums) {
        vector<int> s;
        int len=nums.size();
        vector<int> lmins(len,0);
        int res=0;
        for (int i = 0; i < len; ++i) {
            while (!s.empty()&&nums[s.back()]>nums[i]) {
                int t= min(i-lmins[s.back()]-1, nums[s.back()]);
                res= max(res,t*t);
                s.pop_back();
            }
            if(s.empty()) lmins[i]=-1;
            else lmins[i]=s.back();
            s.push_back(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_221_H
