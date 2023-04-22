//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_240_H
#define HOT100_2_240_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        while (i<m&&j>=0) {
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_240_H
