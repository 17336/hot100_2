//
// Created by 17336 on 2023/4/12.
//

#ifndef HOT100_2_309BEST_H
#define HOT100_2_309BEST_H

#include <vector>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell_max=0,buy_max=-prices[0],hold_max=0;
        int len=prices.size();
        for (int i = 1; i < len; ++i) {
            int last_sell=sell_max,last_buy=buy_max,last_hold=hold_max;
            buy_max= max(last_buy,last_hold-prices[i]);
            sell_max= max(last_sell,last_buy+prices[i]);
            hold_max= max(last_hold,last_sell);
        }
        return max(sell_max, max(buy_max,hold_max));
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#endif //HOT100_2_309BEST_H
