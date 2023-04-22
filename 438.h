//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_438_H
#define HOT100_2_438_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1=s.size(),len2=p.size();
        if(len1<len2) return {};
        vector<int> countp(26,0);
        for (char c:p) {
            countp[c-'a']++;
        }
        vector<int> res;
        vector<int> counts(26,0);
        int i=0,j=0;
        while (i<len1) {
            // 右指针尽可能右移，当右移不符合条件时，停止右移
            while (j<len1&&counts[s[j]-'a']<countp[s[j]-'a']) {
                ++counts[s[j]-'a'];
                ++j;
                if(countp==counts) res.push_back(i);
            }
            if(j==len1) return res;
            // 右指针不能右移时，左指针右移
            --counts[s[i]-'a'];
            ++i;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)



#endif //HOT100_2_438_H
