//
// Created by 17336 on 2023/4/16.
//

#ifndef HOT100_2_347_H
#define HOT100_2_347_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct comp{
            bool operator()(const vector<int> &a,const vector<int> &b) {
                return a[1]>b[1];
            }
        };
        sort(nums.begin(),nums.end());
        priority_queue<vector<int>,vector<vector<int>>,comp> q;
        int i=0,len=nums.size();
        while (i<len) {
            int count=1;
            ++i;
            while (i<len&&nums[i-1]==nums[i]) {
                ++count;
                ++i;
            }
            if(q.size()<k) q.push({nums[i-1],count});
            else if(q.top()[1]<count) {
                q.pop();
                q.push({nums[i-1],count});
            }
        }
        vector<int> res(k);
        for (int j = 0; j < k; ++j) {
            res[j]=q.top()[0];
            q.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_347_H
