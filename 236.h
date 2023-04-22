//
// Created by 17336 on 2023/4/9.
//

#ifndef HOT100_2_236_H
#define HOT100_2_236_H
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x,TreeNode *l,TreeNode*r) : val(x), left(l), right(r) {}
};

#include <stack>

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res= nullptr;
        lowestCommonAncestor(root,p,q,res);
        return res;
    }

    // 当root还有p、q至少一个，返回true；当root是p、q最近祖先，置res=root
    bool lowestCommonAncestor(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *&res){
        TreeNode *left= nullptr,*right= nullptr;
        bool lefthas= false,righthas= false;
        if(root->left) lefthas= lowestCommonAncestor(root->left,p,q,left);
        if(left) {
            res=left;
            return true;
        }
        if(root->right) righthas= lowestCommonAncestor(root->right,p,q,right);
        if(right) {
            res= right;
            return true;
        }
        if(lefthas&&righthas||((lefthas||righthas)&&(root==p||root==q))) {
            res=root;
            return true;
        }
        return righthas||lefthas||root==p||root==q;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_236_H
