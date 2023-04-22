//
// Created by 17336 on 2023/4/15.
//

#ifndef HOT100_2_338_H
#define HOT100_2_338_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        res[0]=0;
        int i=1;
        int j=1;
        while (i<=n) {
            for (int k = 0; k < j && i<=n; ++k) {
                res[i]=res[k]+1;
                ++i;
            }
            j*=2;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_338_H
