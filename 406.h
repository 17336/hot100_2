//
// Created by 17336 on 2023/4/17.
//

#ifndef HOT100_2_406_H
#define HOT100_2_406_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });
        int len=people.size();
        for (int i = 0; i < len; ++i) {
            int k=people[i][1],h=people[i][0];
            int j=i-1;
            while (j>=k) {
                people[j+1]=people[j];
                --j;
            }
            people[j+1]={h,k};
        }
        return people;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_406_H
