//
// Created by 17336 on 2023/3/31.
//

#ifndef HOT100_2_23_H
#define HOT100_2_23_H

#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct comp{
            bool operator()(ListNode *a, ListNode *b) {
                if(!a) return true;
                if(!b) return false;
                return a->val > b->val;
            }
        };
        ListNode *res=new ListNode(), *q=res;
        priority_queue<ListNode *,vector<ListNode *>, comp> p(comp(),lists);
        while (!p.empty()) {
            ListNode *t = p.top();
            if(t) {
                q->next=t;
                t=t->next;
                q=q->next;
            }
            p.pop();
            if(t) p.push(t);
        }
        q->next= nullptr;
        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_23_H
