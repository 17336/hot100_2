//
// Created by 17336 on 2023/4/6.
//

#ifndef HOT100_2_142_H
#define HOT100_2_142_H

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode *fast=head,*slow=head;
        while (fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(fast== nullptr||fast->next== nullptr) return nullptr;
        slow=head;
        while (fast!=slow) {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_142_H
