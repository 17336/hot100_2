//
// Created by 17336 on 2023/4/16.
//

#ifndef HOT100_2_394_H
#define HOT100_2_394_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string decodeString(string s) {
        string res;
        decodeString(s,0,res);
        return res;
    }

    int decodeString(string &s,int begin,string &res) {
        int len=s.size();
        int i=begin;
        while (i<len) {
            if(s[i]==']') {
                ++i;
                return i;
            }
            if(s[i]=='[') ++i;
            else if(isdigit(s[i])) {
                int count= todigit(s,i);
                string temp;
                i=decodeString(s,i+1,temp);
                while (count-- > 0) res.append(temp);
            }
            else res.push_back(s[i++]);
        }
        return i;
    }
    int todigit(string &s,int &begin) {
        int res=0;
        while (begin<s.size()&& isdigit(s[begin])) {
            res=res*10+s[begin]-'0';
            ++begin;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_394_H
