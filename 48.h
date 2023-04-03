//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_48_H
#define HOT100_2_48_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0;i<n;++i) {
            for (int j=0;j<i;++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<n/2;++j) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_48_H
