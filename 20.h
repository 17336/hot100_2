//
// Created by 17336 on 2023/3/28.
//

#ifndef HOT100_2_20_H
#define HOT100_2_20_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (char c: s) {
            if (c == '[' || c == '{' || c == '(') {
                sta.push(c);
            }
            else if (sta.empty())
                return false;
            else if (c == ']') {
                if (sta.top() == '[') sta.pop();
                else return false;
            } else if (c == ')') {
                if (sta.top() == '(') sta.pop();
                else return false;
            } else if (c == '}') {
                if (sta.top() == '{') sta.pop();
                else return false;
            } else return false;
        }
        return sta.empty();
    }
};

#endif //HOT100_2_20_H
