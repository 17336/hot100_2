//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_94_NOT_RECURSIVE_H
#define HOT100_2_94_NOT_RECURSIVE_H

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode *> stack;
        TreeNode *p=root;
        vector<int> res;
        while (!stack.empty()||p) {
            if(p) {
                stack.push_back(p);
                p=p->left;
            }
            else {
                p=stack.back();
                res.push_back(p->val);
                stack.pop_back();
                p=p->right;
            }
        }
        return res;
    }
};

#endif //HOT100_2_94_NOT_RECURSIVE_H
