//
// Created by 17336 on 2023/4/5.
//

#ifndef HOT100_2_136_H
#define HOT100_2_136_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits=0,len=nums.size();
        for (int i=0;i<len;++i) {
            bits^=nums[i];
        }
        return bits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_136_H
