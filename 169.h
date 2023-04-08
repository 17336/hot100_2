//
// Created by 17336 on 2023/4/7.
//

#ifndef HOT100_2_169_H
#define HOT100_2_169_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num,count=0;
        for (int i:nums) {
            if(count==0) {
                count=1;
                num=i;
            }
            else {
                if(i==num) ++count;
                else --count;
            }
        }
        return num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_169_H
