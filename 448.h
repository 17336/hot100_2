//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_448_H
#define HOT100_2_448_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;++i) {
            int x=nums[i]>0?nums[i]:-nums[i];
            if(nums[x-1]>0) nums[x-1]=-nums[x-1];
        }
        vector<int> res;
        for (int i=0;i<n;++i) {
            if(nums[i] >0) res.push_back(i+1);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_448_H
