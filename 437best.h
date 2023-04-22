//
// Created by 17336 on 2023/4/18.
//

#ifndef HOT100_2_437BEST_H
#define HOT100_2_437BEST_H

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
        unordered_map<long long,int> m;
        m[0]=1;
        return pathSum(root,0,targetSum,m);
    }

    int pathSum(TreeNode *root,long long prefixSum,int targetSum,unordered_map<long long,int> &m) {
        if(!root) return 0;
        prefixSum+=root->val;
        int res=0;
        if(m.count(prefixSum-targetSum)) res=m[prefixSum-targetSum];
        m[prefixSum]++;
        res+= pathSum(root->left,prefixSum,targetSum,m);
        res+= pathSum(root->right,prefixSum,targetSum,m);
        m[prefixSum]--;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#endif //HOT100_2_437BEST_H
