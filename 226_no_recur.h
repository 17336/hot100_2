//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_226_NO_RECUR_H
#define HOT100_2_226_NO_RECUR_H

//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_226_H
#define HOT100_2_226_H
#include <stack>
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
        std::stack<TreeNode *>s;
        TreeNode *p=root;
        while (p||!s.empty()) {
            if(p){
                TreeNode *left=p->left;
                p->left=p->right;
                p->right=left;
                s.push(p);
                p=p->left;
            }
            else {
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_226_H


#endif //HOT100_2_226_NO_RECUR_H
