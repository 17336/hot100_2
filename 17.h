//
// Created by ByteDance on 2023/3/23.
//

#ifndef HOT100_2_17_H
#define HOT100_2_17_H

#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    const vector<string> num2letter{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        string path;
        backtrace(path,res,digits,0);
        return res;
    }

    void backtrace(string &path, vector<string> &res, string &digits, int pos) {
        if(pos == digits.length()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < num2letter[digits[pos] - '2'].size(); ++i) {
            path.push_back(num2letter[digits[pos] - '2'][i]);
            backtrace(path,res,digits,pos+1);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_17_H
