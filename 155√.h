//
// Created by 17336 on 2023/4/7.
//

#ifndef HOT100_2_155_H
#define HOT100_2_155_H

#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)

class MinStack {
    std::vector<int> stack;
    std::vector<int> min_stack;
public:
    MinStack() {
    }

    void push(int i) {
        if(min_stack.empty()||i<=min_stack.back()) min_stack.push_back(i);
        stack.push_back(i);
    }

    void pop() {
        int v=stack.back();
        if(min_stack.back()==v) min_stack.pop_back();
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min_stack.back();
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
