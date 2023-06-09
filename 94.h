//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_94_H
#define HOT100_2_94_H

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
        if(!root) return {};
        vector<int> left= inorderTraversal(root->left),right= inorderTraversal(root->right);
        left.push_back(root->val);
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_94_H
