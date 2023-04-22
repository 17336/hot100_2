//
// Created by 17336 on 2023/4/17.
//

#ifndef HOT100_2_437_H
#define HOT100_2_437_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
#ifndef TREENODE
#define TREENODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        int res = pSum(root, targetSum);
        res+=pathSum(root->left, targetSum);
        res+=pathSum(root->right, targetSum);
        return res;
    }

    int pSum(TreeNode *root, long long targetSum) {
        if (!root) return 0;
        int res = 0;
        if (targetSum == root->val) res += 1;
        res += pSum(root->left, targetSum - root->val);
        res += pSum(root->right, targetSum - root->val);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_437_H
