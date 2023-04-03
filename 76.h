//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_76_H
#define HOT100_2_76_H

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        if(m<n) return "";
        vector<int> tletter(52,0),sletter(52,0);
        for (int i=0;i<n;++i) {
            if(isupper(t[i])) tletter[t[i]-'A']++;
            else tletter[t[i]-'a'+26]++;
        }
        int from=-1,len=INT_MAX;
        int l=0,r=-1;
        while (l<m){
            while (!greater(sletter,tletter)&&r+1<m) {
                ++r;
                if(isupper(s[r])) sletter[s[r]-'A']++;
                else sletter[s[r]-'a'+26]++;
            }
            if(!greater(sletter,tletter)) break;
            if(r-l+1<len) {
                from = l;
                len = r - l + 1;
                if(len==t.size()) break;
            }
            if (isupper(s[l])) sletter[s[l] - 'A']--;
            else sletter[s[l] - 'a'+26]--;
            ++l;
        }
        if(from==-1) return "";
        return s.substr(from,len);
    }
    bool greater(const vector<int> &a,const vector<int> &b) {
        for (int i=0;i<a.size();++i) {
            if(a[i]<b[i]) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_76_H
