//
// Created by 17336 on 2023/3/31.
//


#ifndef HOT100_2_32_H
#define HOT100_2_32_H

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        int l=0,res=0,last=0;
        for (int i =0;i<s.size();++i) {
            if(s[i]=='(') ++l;
            else --l;
            if(l<0) {
                while (i<s.size()&&s[i]==')') ++i;
                l=1;
                last = i;
            }
            else if(l==0) {
                res= max(res,i-last+1);
            }
        }
        int r=0;
        last=s.size()-1;
        for (int i=s.size()-1;i>=0;--i) {
            if(s[i]==')') ++r;
            else --r;
            if(r<0) {
                while (i>=0 &&s[i]=='(') --i;
                r=1;
                last=i;
            }
            else if(r==0) {
                res= max(res,last-i+1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_32_H
