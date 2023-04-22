//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_98_H
#define HOT100_2_98_H

#include <climits>
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
    bool isValidBST(TreeNode* root) {
        int a,b;
        return isValidBST(root,a,b);
    }

    bool isValidBST(TreeNode* root,int &tmax,int &tmin) {
        if(!root) {
            return true;
        }
        tmax=root->val;
        tmin=root->val;
        int lmin,lmax,rmin,rmax;
        if(root->left&&!isValidBST(root->left,lmax,lmin)) return false;
        if(root->right&&!isValidBST(root->right,rmax,rmin)) return false;
        if((root->left&&lmax>=root->val)||(root->right&&root->val>=rmin)) return false;
        if(root->left) {
            tmin=lmin;
        }
        if(root->right) tmax=rmax;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_98_H
