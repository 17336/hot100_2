//
// Created by 17336 on 2023/4/19.
//

#ifndef HOT100_2_538_H
#define HOT100_2_538_H

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
    TreeNode* convertBST(TreeNode* root) {
        covert(root,0);
        return root;
    }

    // other是大于这颗子树
    int covert(TreeNode* root,int other) {
        if(!root) return 0;
        int right= covert(root->right,other);
        int left= covert(root->left,root->val+right+other);
        int res=root->val+left+right;
        root->val+=right+other;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_538_H
