//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_543_H
#define HOT100_2_543_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int a;
        return diameterOfBinaryTree(root,a)-1;
    }

    int diameterOfBinaryTree(TreeNode* root,int &x) {
        if(!root) {
            x=0;
            return 0;
        }
        int lx,rx;
        int lres= diameterOfBinaryTree(root->left,lx);
        int rres= diameterOfBinaryTree(root->right,rx);
        int res= max(max(lres,rres),lx+rx+1);
        x= max(lx,rx)+1;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_543_H
