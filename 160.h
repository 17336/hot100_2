//
// Created by 17336 on 2023/4/7.
//

#ifndef HOT100_2_160_H
#define HOT100_2_160_H

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *p1=headA,*p2=headB;
        while (p1) {
            len1++;
            p1=p1->next;
        }
        while (p2) {
            len2++;
            p2=p2->next;
        }
        int k;
        if(len1<len2) {
            p1=headB;
            p2=headA;
            k=len2-len1;
        }
        else {
            p1=headA;
            p2=headB;
            k=len1-len2;
        }
        while (k--) {
            p1=p1->next;
        }
        while (p1&&p2) {
            if(p1==p2) return p1;
            p1=p1->next;
            p2=p2->next;
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_160_H
