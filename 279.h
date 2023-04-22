//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_279_H
#define HOT100_2_279_H

#include <vector>
#include <climits>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(n+1,0);
        for (int i = 1; i <= n; ++i) {
            int res=INT_MAX;
            for (int j = 1; j*j <= i; ++j) {
                res= min(res,nums[i-j*j]+1);
            }
            nums[i]=res;
        }
        return nums.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_279_H
