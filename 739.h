//
// Created by 17336 on 2023/4/21.
//

#ifndef HOT100_2_739_H
#define HOT100_2_739_H

#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int len=temperatures.size();
        vector<int> res(len,0);
        for (int i = 0; i < len; ++i) {
            while (!s.empty()&&temperatures[i]>temperatures[s.top()]) {
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_739_H
