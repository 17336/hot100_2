//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_34_H
#define HOT100_2_34_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,len=nums.size(),r=len-1;
        int lr=-1,rr=-1;
        if(nums.empty()) return {-1,-1};
        while (l<=r) {
            int m=(l+r)/2;
            if(nums[m]<target) l=m+1;
            else if(nums[m] >target) r=m-1;
            else if(m==0) {
                lr=m;
                break;
            }
            else if(nums[m-1] == nums[m]) r=m-1;
            else {
                lr=m;
                break;
            }
        }
        l=0;
        r=len-1;
        while (l<=r) {
            int m=(l+r)/2;
            if(nums[m]<target) l=m+1;
            else if(nums[m] >target) r=m-1;
            else if(m==len-1) {
                rr=m;
                break;
            }
            else if(nums[m+1] == nums[m]) l=m+1;
            else {
                rr=m;
                break;
            }
        }
        return {lr,rr};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_34_H
