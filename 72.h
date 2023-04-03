//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_72_H
#define HOT100_2_72_H

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(),len2=word2.size();
        vector<vector<int>> dps(len1+1,vector<int> (len2+1));
        for (int i=0;i<len1+1;++i) {
            for (int j=0;j<len2+1;++j) {
                if(i==0) dps[i][j]=j;
                else if(j==0) dps[i][j]=i;
                else {
                    int t= min(dps[i-1][j],dps[i][j-1])+1;
                    t= min(t,dps[i-1][j-1]+(word1[i-1]!=word2[j-1]));
                    dps[i][j]=t;
                }
            }
        }
        return dps[len1][len2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_72_H
