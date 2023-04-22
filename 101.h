//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_101_H
#define HOT100_2_101_H

#include <queue>

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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        std::vector<TreeNode *> q;
        q.push_back(root);
        TreeNode *p;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len / 2; ++i) {
                if (q[i] == q[len - i - 1] ||
                    (q[i] != nullptr && q[len - i - 1] != nullptr && q[i]->val == q[len - i - 1]->val))
                    continue;
                else return false;
            }
            std::vector<TreeNode *> temp;
            for (int i = 0; i < len; ++i) {
                if(q[i]) {
                    temp.push_back(q[i]->left);
                    temp.push_back((q[i]->right));
                }
            }
            q.swap(temp);
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_101_H
