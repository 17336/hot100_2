//
// Created by 17336 on 2023/4/12.
//

#ifndef HOT100_2_301_H
#define HOT100_2_301_H

#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int len = s.size();
        vector<vector<int>> invalid;
        int last = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') ++l;
            else if (s[i] == ')') {
                if (l > 0) --l;
                else {
                    invalid.push_back({last, i});
                    last = i + 1;
                    l = 0;
                }
            }
        }
        int boundary = invalid.size();
        last = len - 1;
        int r = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == ')') ++r;
            else if (s[i] == '(') {
                if (r > 0) --r;
                else {
                    invalid.push_back({i, last});
                    last = i - 1;
                    r = 0;
                }
            }
        }
        if(invalid.empty()) return {s};
        reverse(invalid.begin()+boundary,invalid.end());
        vector<string> res;
        string path=s.substr(0,invalid.front()[0]);
        backtrace(path,invalid,0,s,boundary,res);
        return res;

    }

    void backtrace(string &path, vector<vector<int>> &invalid, int from,
                   string &s, int boundary, vector<string> &res) {
        if (from>=invalid.size()) {
            res.push_back(path);
            return;
        }
        int begin=invalid[from][0],end=invalid[from][1],i=begin;
        char c=from<boundary?')':'(';
        while (i<=end) {
            if(s[i]==c&&(i==begin||s[i-1]!=c)) {
                string s1=s.substr(begin,end-begin+1);
                s1.erase(i-begin,1);
                int temp=path.size();
                path.append(s1);
                if(from==invalid.size()-1) path.append(s.substr(end+1));
                else path.append(s.substr(end+1,invalid[from+1][0]-end-1));
                backtrace(path,invalid,from+1,s,boundary,res);
                path.erase(temp);
            }
            ++i;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_301_H
