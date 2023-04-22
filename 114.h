//
// Created by 17336 on 2023/4/4.
//

#ifndef HOT100_2_141_H
#define HOT100_2_141_H

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
    void flatten(TreeNode *root) {
        TreeNode *a, *b;
        flatten(root, &a, &b);
    }

    void flatten(TreeNode *root, TreeNode **first, TreeNode **end) {
        if (!root) {
            *first = nullptr;
            *end = nullptr;
            return;
        }
        TreeNode *lf, *le, *rf, *re;
        flatten(root->left, &lf, &le);
        flatten(root->right, &rf, &re);
        TreeNode *p = root;
        root->left = nullptr;
        if (lf) {
            p->right = lf;
            p = le;
        }
        p->right = rf;
        *first = root;
        if (re)
            *end = re;
        else if (le)
            *end = le;
        else *end = root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_141_H
