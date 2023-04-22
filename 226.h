//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_226_H
#define HOT100_2_226_H
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode *left = invertTree(root->left);
        TreeNode *right= invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_226_H
