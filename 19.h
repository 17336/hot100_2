//
// Created by ByteDance on 2023/3/24.
//

#ifndef HOT100_2_19_H
#define HOT100_2_19_H

//leetcode submit region begin(Prohibit modification and deletion)

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode pilot(-1,head);
        ListNode *fast = head, *slow=head,*pre=&pilot;
        while (n--) {
            fast=fast->next;
        }
        while (fast) {
            fast=fast->next;
            slow=slow->next;
            pre=pre->next;
        }
        pre->next=slow->next;
        return pilot.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_19_H
