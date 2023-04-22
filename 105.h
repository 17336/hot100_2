//
// Created by 17336 on 2023/4/4.
//

#ifndef HOT100_2_105_H
#define HOT100_2_105_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder,int pi,int pj, vector<int>& inorder,int ii,int ij) {
        if(pi>pj) return nullptr;
        TreeNode *node=new TreeNode(preorder[pi]);
        if(pi==pj) return node;
        int k=ii;
        while (inorder[k]!=preorder[pi]) ++k;
        TreeNode *left= buildTree(preorder,pi+1,k+pi-ii,inorder,ii,k-1);
        TreeNode *right= buildTree(preorder,k+pi-ii+1,pj,inorder,k+1,ij);
        node->left=left;
        node->right=right;
        return node;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_105_H
