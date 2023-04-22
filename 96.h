//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_96_H
#define HOT100_2_96_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dps(n+1,0);
        int i=1;
        dps[0]=1;
        while (i<=n) {
            int res=0;
            for (int j=0;j<i/2;++j) {
                res+=dps[i-j-1]*dps[j];
            }
            res*=2;
            if(i%2) res+=dps[i/2]*dps[i/2];
            dps[i]=res;
            ++i;
        }
        return dps[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_96_H
