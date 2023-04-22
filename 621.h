//
// Created by 17336 on 2023/4/20.
//

#ifndef HOT100_2_621_H
#define HOT100_2_621_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cs(26,0);
        for (char c:tasks) {
            cs[c-'A']++;
        }
        sort(cs.begin(),cs.end());
        int maxCount=cs[25];
        int res=(maxCount-1)*(n+1)+1;
        for (int i = 24; i >=0 ; --i) {
            if(cs[i]==maxCount) ++res;
            else break;
        }
        return max((size_t)res,tasks.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)



#endif //HOT100_2_621_H
