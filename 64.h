//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_64_H
#define HOT100_2_64_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for (int i=m-1;i>=0;--i) {
            for (int j=n-1;j>=0;--j){
                if(i==m-1&&j==n-1) continue;
                else if(i==m-1) grid[i][j]+=grid[i][j+1];
                else if(j==n-1) grid[i][j]+=grid[i+1][j];
                else grid[i][j]+= min(grid[i+1][j],grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_64_H
