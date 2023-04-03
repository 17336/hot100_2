//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_56_H
#define HOT100_2_56_H

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        struct {
            bool operator()(const vector<int> &a,const vector<int> &b) {
                return a[0]<b[0];
            }
        }comp;
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> res{intervals[0]};
        int len=intervals.size();
        for (int i=1;i<len;++i) {
            if(intervals[i][0]<=res.back()[1]) {
                res.back()[1]= max(res.back()[1],intervals[i][1]);
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_56_H
