//
// Created by 17336 on 2023/4/21.
//

#ifndef HOT100_2_647_H
#define HOT100_2_647_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        string ns="*";
        for (char c:s) {
            ns.push_back(c);
            ns.push_back('*');
        }
        int res=0,len=ns.size();
        int mr=-1,x=-1;
        vector<int> radixs(len,0);
        radixs[0]=1;
        for (int i = 1; i < len-1; ++i) {
            int l=i,r=i;
            if(mr>i) {
                int t= min(mr-i+1,radixs[2*x-i]);
                l=i+1-t;
                r=i+t-1;
            }
            while (l-1>=0&&r+1<len&&ns[l-1]==ns[r+1]) {
                --l;
                ++r;
            }
            radixs[i]=r-i+1;
            if(r>mr) {
                mr=r;
                x=i;
            }
            res+=(radixs[i])/2;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)



#endif //HOT100_2_647_H
