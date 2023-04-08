//
// Created by 17336 on 2023/4/6.
//

#ifndef HOT100_2_155_H
#define HOT100_2_155_H

#include <vector>
#include <climits>

//leetcode submit region begin(Prohibit modification and deletion)
struct ListNode {
    ListNode *next;
    ListNode *pre;
    int val;
    int index;

    ListNode(int i, int v) : index(i), val(v),next(nullptr),pre(nullptr) {

    }
};

class MinStack {
    std::vector<ListNode *> heap;
    ListNode *list;
    ListNode *end;
public:
    MinStack() {
        list = new ListNode(0, INT_MAX);
        end = list;
        heap.push_back(list);
    }

    void push(int val) {
        ListNode *t = new ListNode(heap.size(), val);
        heap.push_back(t);
        end->next = t;
        t->pre=end;
        end=t;
        upAdjust(heap.size()-1);
    }

    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
        heap[i]->index = i;
        heap[j]->index = j;
    }

    void upAdjust(int i) {
        while (i > 0) {
            int p = i % 2 ? (i - 1) / 2 : (i - 2) / 2;
            if (i == heap.size() - 1) {
                if (heap[p]->val <= heap[i]->val) return;
                swap(i, p);
                i = p;
            } else {
                int bro = i % 2 ? p * 2 + 2 : p * 2 + 1;
                int m;
                if (heap[bro]->val > heap[i]->val) m = i;
                else m=bro;
                if(heap[m]->val >= heap[p]->val) return;
                swap(m,p);
                i=p;
            }
        }
    }

    void pop() {
        ListNode *t=end;
        end=end->pre;
        end->next= nullptr;
        int i=t->index;
        swap(i,heap.size()-1);
        heap.pop_back();
        downAdjust(i);
    }

    void downAdjust(int i) {
        int n=heap.size();
        while (i<=n/2-1) {
            int l=2*i+1,r=2*i+1;
            int m=l;
            if(r<n && heap[r]->val<heap[l]->val) m=r;
            if(heap[i]->val<=heap[m]->val) return;
            swap(i,m);
            i=m;
        }
    }

    int top() {
        return end->val;
    }

    int getMin() {
        return heap[0]->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_155_H
