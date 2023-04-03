//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_42_H
#define HOT100_2_42_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> stack;
        int res=0;
        for (int i=0;i<height.size();++i) {
            int h=height[i],last=0;
            while (!stack.empty()&&h>=height[stack.back()]) {
                res+= (min(h,height[stack.back()])-last)*(i-stack.back()-1);
                last=height[stack.back()];
                stack.pop_back();
            }
            if(!stack.empty()) res+=(min(h,height[stack.back()])-last)*(i-stack.back()-1);
            stack.push_back(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_42_H
