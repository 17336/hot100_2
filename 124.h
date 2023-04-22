//
// Created by 17336 on 2023/4/4.
//

#ifndef HOT100_2_124_H
#define HOT100_2_124_H

#include <algorithm>

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
    int maxPathSum(TreeNode* root) {
        int a;
        return maxPathSum(root,a);
    }

    int maxPathSum(TreeNode *root,int &pmax) {
        int lpmax=-1,rpmax=-1,res=root->val;
        if(root->left) res= std::max(maxPathSum(root->left,lpmax),res);
        if(root->right) res=std::max(maxPathSum(root->right,rpmax),res);
        pmax=root->val;
        if(lpmax>0||rpmax>0) pmax+=std::max(lpmax,rpmax);
        int t=root->val;
        if(lpmax>0) t+=lpmax;
        if(rpmax>0) t+=rpmax;
        res=std::max(res,t);
        return res;
    }
};

#endif //HOT100_2_124_H
