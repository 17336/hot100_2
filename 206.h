//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_206_H
#define HOT100_2_206_H
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

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *q=head->next,*pre=head;
        while (q) {
            ListNode *temp=q->next;
            q->next=pre;
            pre=q;
            q=temp;
        }
        head->next= nullptr;
        return pre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_206_H
