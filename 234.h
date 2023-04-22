//
// Created by 17336 on 2023/4/9.
//

#ifndef HOT100_2_234_H
#define HOT100_2_234_H

#include <stack>

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
    bool isPalindrome(ListNode* head) {
        std::stack<int> s;
        ListNode *p=head;
        while (p) {
            s.push(p->val);
            p=p->next;
        }
        p=head;
        while (p) {
            if(p->val!=s.top()) return false;
            p=p->next;
            s.pop();
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#endif //HOT100_2_234_H
