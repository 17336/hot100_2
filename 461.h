//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_461_H
#define HOT100_2_461_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y;
        int res=0;
        while (z) {
            res++;
            z&=z-1;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_461_H
