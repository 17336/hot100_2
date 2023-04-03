//
// Created by 17336 on 2023/4/2.
//

#ifndef HOT100_2_75_H
#define HOT100_2_75_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3]={0,0,0};
        for (auto i:nums) {
            ++colors[i];
        }
        for (int i=0;i<nums.size();++i) {
            if(colors[0]) {
                nums[i]=0;
                colors[0]--;
            }
            else if(colors[1]){
                nums[i]=1;
                colors[1]--;
            }
            else {
                nums[i]=2;
                colors[2]--;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_75_H
