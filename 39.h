//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_39_H
#define HOT100_2_39_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    unordered_map<int,vector<vector<int>>> target_nums{};
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        unordered_set<int> s(candidates.begin(),candidates.end());
        vector<int> cans(s.begin(),s.end()),path;
        backtrace(cans,res, 0,path,target);
        return res;
    }

    void backtrace(vector<int> &cans,vector<vector<int>> &res,int begin,vector<int> &path,int target) {
        if(target<0) return;
        if(target==0) {
            res.push_back(path);
            return;
        }
        while (begin<cans.size()) {
            path.push_back(cans[begin]);
            backtrace(cans,res,begin,path,target-cans[begin]);
            path.pop_back();
            begin++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_39_H
