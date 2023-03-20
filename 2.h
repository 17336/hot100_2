//
// Created by ByteDance on 2023/3/17.
//

#ifndef HOT100_2_2_H
#define HOT100_2_2_H

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int c = 0;
        ListNode *res = new ListNode(0), *p = res;
        while (l1 || l2 || c) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            p->next = new ListNode(sum % 10);
            c = sum / 10;
            p = p->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return res->next;
    }
};


#endif //HOT100_2_2_H
