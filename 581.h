//
// Created by 17336 on 2023/4/20.
//

#ifndef HOT100_2_581_H
#define HOT100_2_581_H

#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int len=nums.size();
        int l=-1,r=-1;

        // 维护一个当前最大值
        int curmax=nums[0];
        // 最小的乱序值下标，xmin最后被移到最左边l处；同时找到最靠右的乱序值，即r处
        int xmin=-1;
        for (int i = 0; i < len; ++i) {
            if(nums[i]>=curmax) curmax=nums[i];
            else {
                if(xmin==-1||nums[i]<nums[xmin]) xmin=i;
                r=i;
            }
        }

        // 找xmin最后被移到的l位置
        if(xmin==-1) return 0;
        for (int i = 0; i < len; ++i) {
            if(nums[i]>nums[xmin]) {
                l=i;
                break;
            }
        }
        return r-l+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_581_H
