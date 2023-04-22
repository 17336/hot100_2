//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_85DP_H
#define HOT100_2_85DP_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<vector<int>>> dps(m, vector<vector<int>>(n));
        vector<vector<int>> lens(m, vector<int>(n)), widths(m, vector<int>(n));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j]!='1') {
                    dps[i][j]={0,0};
                    lens[i][j]=0;
                    widths[i][j]=0;
                    continue;
                }
                int len1=1,wide1=1;
                if(i>0&&j>0) {
                    len1= min(lens[i][j - 1] + 1, dps[i - 1][j - 1][0] + 1);
                    wide1= min(widths[i - 1][j] + 1, dps[i - 1][j - 1][1] + 1);
                }
                else if(j>0) len1= lens[i][j - 1] + 1;
                else if(i>0) wide1= widths[i - 1][j] + 1;
                dps[i][j]={len1, wide1};
                lens[i][j]=len1;
                widths[i][j]=wide1;
                res= max(res, len1 * wide1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_85DP_H
