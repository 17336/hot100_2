//
// Created by 17336 on 2023/4/5.
//

#ifndef HOT100_2_141_H
#define HOT100_2_141_H

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
    bool hasCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while (fast&&slow) {
            if(fast->next) fast=fast->next->next;
            else return false;
            slow=slow->next;
            if(fast&&fast==slow) return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_141_H
