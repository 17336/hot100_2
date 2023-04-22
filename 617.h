//
// Created by 17336 on 2023/4/20.
//

#ifndef HOT100_2_617_H
#define HOT100_2_617_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val+=root2->val;
        root1->left= mergeTrees(root1->left,root2->left);
        root1->right= mergeTrees(root1->right,root2->right);
        return root1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)



#endif //HOT100_2_617_H
