//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_287_H
#define HOT100_2_287_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//        int len=nums.size();
//        for (int i = 0; i < len; ++i) {
//            int j=nums[i]<0?-nums[i]:nums[i];
//            if(nums[j-1]<0) return j;
//            nums[j-1]=-nums[j-1];
//        }
//        return -1;
        //方法二
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            int j=i;
            while (nums[j]!=j+1) {
                int k=nums[nums[j]-1];
                if(k==nums[j]) return nums[j];
                swap(nums[j],nums[nums[j]-1]);
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_287_H
