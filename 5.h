//
// Created by ByteDance on 2023/3/21.
//

#ifndef HOT100_2_5_H
#define HOT100_2_5_H

#include <string>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int ri=-1,rr=-1,len=s.size(),res=0;
        // 在字符之间插入'*'，避免aba和bb回文分类讨论
        string sf="*";
        for (int i = 0; i < len; ++i) {
            sf.push_back(s[i]);
            sf.push_back('*');
        }
        len=sf.size();
        // 记录每个以i为中心的的回文半径
        vector<int> nums(len);
        for (int i = 0; i < len; ++i) {
            int l=i,r=i;
            if(rr>i) {
                int d= min(rr-i+1,nums[2*ri-i]);
                r=i+d-1;
                l=i+1-d;
            }
            while (l>0&&r<len-1 && sf[l-1] == sf[r+1]) {
                --l;
                ++r;
            }
            nums[i] = r-i+1;
            if (r>rr) {
                ri=i;
                rr=r;
                if (rr > len) break;
            }
            if (nums[i] >nums[res]) {
                res=i;
            }
        }
        return s.substr((res+2-nums[res])/2, nums[res]-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_5_H
