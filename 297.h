//
// Created by 17336 on 2023/4/11.
//

#ifndef HOT100_2_297_H
#define HOT100_2_297_H
#include <string>
#include <queue>

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x,TreeNode *l,TreeNode *r) : val(x), left(l), right(r) {}
};
#endif

//leetcode submit region begin(Prohibit modification and deletion)

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        TreeNode *p;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            p=q.front();
            q.pop();
            if(p== nullptr) res.push_back('n');
            else {
                res.append(to_string(p->val));
                q.push(p->left);
                q.push(p->right);
            }
            res.push_back(',');
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        int begin=0;
        TreeNode *root;
        getVal(data,begin,root);
        queue<TreeNode *>q;
        q.push(root);
        TreeNode *p;
        while (!q.empty()) {
            p=q.front();
            q.pop();
            if(!getVal(data,begin,p->left)) return root;
            if(!getVal(data,begin,p->right)) return root;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return root;
    }

    bool getVal(const string &s,int &begin,TreeNode *&res) {
        res= nullptr;
        if(begin>=s.size()-1) return false;
        if(s[begin]==',') begin++;
        bool fu= false;
        if(s[begin]=='-') {
            fu= true;
            ++begin;
        }
        int val=0;
        while (begin<s.size()&&isdigit(s[begin])) {
            val=val*10+s[begin]-'0';
            begin++;
        }
        if(s[begin]=='n') ++begin;
        else res=new TreeNode(fu?-val:val);
        return true;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_297_H
