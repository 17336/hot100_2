//
// Created by 17336 on 2023/4/1.
//

#ifndef HOT100_2_49_H
#define HOT100_2_49_H

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> res;
        for(auto item:strs) {
            string temp=item;
            sort(item.begin(),item.end());
            m[item].push_back(temp);
        }
        for (auto &item:m) {
            res.push_back(item.second);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_49_H
