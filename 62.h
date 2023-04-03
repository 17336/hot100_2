//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_62_H
#define HOT100_2_62_H

#include <unordered_map>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    std::unordered_map<int,int> ms{{1,1}};
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int key=m<n?(m+n*100):(n+m*100);
        if(ms.find(key)!=ms.end()) return ms[key];
        return ms[key]= uniquePaths(m,n-1)+ uniquePaths(m-1,n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_62_H
