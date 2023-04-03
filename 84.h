//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_84_H
#define HOT100_2_84_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        vector<int> stack;
        vector<int> lmins(heights.size(), -1);
        int area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int top = -1;
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                top = stack.back();
                area = max(area, (i - lmins[stack.back()] - 1) * heights[stack.back()]);
                stack.pop_back();
            }
            if (!stack.empty()) {
                if (heights[stack.back()] < heights[i]) lmins[i] = stack.back();
                else lmins[i] = lmins[stack.back()];
            } else if (top != -1)
                lmins[i] = lmins[top];
            stack.push_back(i);
        }
        return area;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_84_H
