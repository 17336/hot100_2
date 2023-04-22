//
// Created by 17336 on 2023/4/15.
//

#ifndef HOT100_2_337_H
#define HOT100_2_337_H

#include <vector>
#include <string>
#include <algorithm>
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
    int rob(TreeNode* root) {
        int a;
        return rob(root,a);
    }

    int rob(TreeNode *root,int &val) {
        if(!root) {
            val=0;
            return 0;
        }
        int left_max,left_n,right_max,right_n;
        left_max= rob(root->left,left_n);
        right_max= rob(root->right,right_n);
        int res= max(root->val+left_n+right_n, left_max+right_max);
        val= left_max+right_max;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_337_H
