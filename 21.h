//
// Created by 17336 on 2023/3/28.
//

#ifndef HOT100_2_21_H
#define HOT100_2_21_H

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res=new ListNode(),*p=res;
        while (list1 && list2) {
            if(list1->val<list2->val) {
                p->next=list1;
                list1=list1->next;
            }
            else {
                p->next=list2;
                list2=list2->next;
            }
            p=p->next;
        }
        if(list1) p->next=list1;
        else if(list2) p->next=list2;
        return res->next;
    }
};

#endif //HOT100_2_21_H
