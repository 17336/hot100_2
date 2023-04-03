//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_70_H
#define HOT100_2_70_H

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
        int l2=1,l1=1,p=1;
        while (p!=n) {
            ++p;
            int temp=l1;
            l1+=l2;
            l2=temp;
        }
        return l1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_70_H
