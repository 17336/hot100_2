//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_239_H
#define HOT100_2_239_H

#include <vector>
#include <deque>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len=nums.size(),i=0;
        deque<int> maxs;
        for (; i < k; ++i) {
            while (!maxs.empty()&&maxs.back()<nums[i]) maxs.pop_back();
            maxs.push_back(nums[i]);
        }
        vector<int> res{maxs.front()};
        for (; i < len; ++i) {
            if(nums[i-k]==maxs.front()) maxs.pop_front();
            while (!maxs.empty()&&maxs.back()<nums[i]) maxs.pop_back();
            maxs.push_back(nums[i]);
            res.push_back(maxs.front());
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_239_H
