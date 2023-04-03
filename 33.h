//
// Created by 17336 on 2023/3/31.
//

#ifndef HOT100_2_33_H
#define HOT100_2_33_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先二分搜索旋转点
        int l=0,r=nums.size()-1,k=-1,len=nums.size();
        int first=nums[0],end=nums.back();
        if(first<=end) return find(nums,0,len-1,target);
        while (l<=r) {
            int m=(l+r)/2;
            if(m>=nums.size()-1) break;
            if(nums[m]>nums[m+1]) {
                k=m;
                break;
            }
            else if(nums[m]>=first) l=m+1;
            else r=m-1;
        }
        // 再二分搜索target
        int res= find(nums,0,k,target);
        if(res>=0) return res;
        res= find(nums,k+1,len-1,target);
        return res;
    }

    int find(vector<int> &nums,int l, int r,int target) {
        while (l<=r) {
            int m=(l+r)/2;
            if(nums[m]==target) return m;
            else if(nums[m] >target) r=m-1;
            else l=m+1;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_33_H
