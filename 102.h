//
// Created by 17336 on 2023/4/3.
//

#ifndef HOT100_2_102_H
#define HOT100_2_102_H

#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        TreeNode *p;
        while (!q.empty()) {
            int len=q.size();
            res.emplace_back(len);
            for (int i=0;i<len;++i) {
                p=q.front();
                q.pop();
                res.back()[i]=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_102_H
