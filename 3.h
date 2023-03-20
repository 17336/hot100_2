//
// Created by ByteDance on 2023/3/17.
//

#ifndef HOT100_2_3_H
#define HOT100_2_3_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1, len = s.size(), res = 0;
        unordered_set<char> set;
        while (r < len) {
            while (l <= r && set.find(s[r+1]) != set.end()) {
                set.erase(s[l]);
                ++l;
            }
            ++r;
            if(r>=len) return res;
            set.emplace(s[r]);
            res= max(res,r-l+1);
        }
        return res;
    }
};

#endif //HOT100_2_3_H
