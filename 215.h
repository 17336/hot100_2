//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_215_H
#define HOT100_2_215_H

#include <vector>
#include <cmath>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,len=nums.size(),r=nums.size()-1;
        while (true) {
            int t=rand()%(r-l+1)+l;
            swap(nums[l],nums[t]);
            int tl=l,tr=r;
            int pilot=nums[l];
            while (l<r) {
                while (l<r&&nums[r]>=pilot) --r;
                nums[l]=nums[r];
                while (l<r&&nums[l]<=pilot) ++l;
                nums[r]=nums[l];
            }
            nums[l]=pilot;
            if(l==len-k) return pilot;
            else if(l<len-k) {
                ++l;
                r=tr;
            }
            else {
                --r;
                l=tl;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_215_H
