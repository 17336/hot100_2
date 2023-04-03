//
// Created by 17336 on 2023/3/31.
//

#ifndef HOT100_2_22_H
#define HOT100_2_22_H

#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrace(res, path, 0,n);
        return res;
    }

    void backtrace(vector<string> &res,string &path,int ll,int n) {
        if (path.size()==2*n) {
            res.push_back(path);
            return;
        }
        if(ll+(path.size()-ll)/2<n) {
            path.push_back('(');
            backtrace(res,path,ll+1,n);
            path.pop_back();
        }
        if(ll>0) {
            path.push_back(')');
            backtrace(res,path,ll-1,n);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_22_H
