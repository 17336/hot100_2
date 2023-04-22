//
// Created by 17336 on 2023/4/4.
//

#ifndef HOT100_2_104_H
#define HOT100_2_104_H

#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_104_H
