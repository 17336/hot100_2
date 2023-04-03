//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_79_H
#define HOT100_2_79_H

#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int steps[5]={0,1,0,-1,0};
public:
    bool exist(vector<vector<char>> board, string word) {
        vector<vector<int>> visted(board.size(),vector<int> (board[0].size(),0));
        int m=board.size(),n=board[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                visted[i][j]=1;
                if(dfs(board,i,j,visted,word,0)) return true;
                visted[i][j]=0;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board,int i,int j,vector<vector<int>> &visted,string &word,int k) {
        if(board[i][j]!=word[k]) return false;
        if(k==word.size()-1) return true;
        int m=board.size(),n=board[0].size();
        for (int p=0;p<4;++p) {
            int ni=i+steps[p],nj=j+steps[p+1];
            if(ni>=0&&ni<m&&nj>=0&&nj<n&&visted[ni][nj]==0) {
                visted[ni][nj]=1;
                if(dfs(board,ni,nj,visted,word,k+1))return true;
                visted[ni][nj]=0;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_79_H
