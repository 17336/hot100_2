//
// Created by ByteDance on 2023/3/21.
//

#ifndef HOT100_2_11_H
#define HOT100_2_11_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size(),i=0,j=len-1;
        int res=0;
        while (i<j) {
            res= max(res, min(height[j],height[i])*(j-i));
            if(height[i] <=height[j]) ++i;
            else --j;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_11_H
