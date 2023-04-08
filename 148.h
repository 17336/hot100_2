//
// Created by 17336 on 2023/4/6.
//

#ifndef HOT100_2_148_H
#define HOT100_2_148_H

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *fast=head->next,*slow=head;
        while (fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *b= sortList(slow->next);
        slow->next= nullptr;
        ListNode *a=sortList(head);
        return merge(a,b);
    }

    ListNode *merge(ListNode *a,ListNode *b) {
        ListNode res(-1),*p=&res;
        while (a&&b) {
            if(a->val<b->val) {
                p->next=a;
                a=a->next;
            }
            else {
                p->next=b;
                b=b->next;
            }
            p=p->next;
        }
        if(a) p->next=a;
        else if(b) p->next=b;
        else p->next= nullptr;
        return res.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_148_H
