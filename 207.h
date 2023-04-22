//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_207_H
#define HOT100_2_207_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 对于一条边0->1来说，必须同时在0结点和1结点都记录这个信息
        // 在0中记录0->1，这样删去0时，可以快速迭代所有原来被0指向的边
        unordered_map<int,vector<int>> tos;
        // 在1中记录0->1，这样删去别的结点时，可以知道指向1的边的数量，当数量为0时可以学习
        unordered_map<int,unordered_set<int>> froms;
        for(auto &item:prerequisites) {
            tos[item[1]].push_back(item[0]);
            froms[item[0]].insert(item[1]);
            froms[item[1]];
        }
        vector<int> canStudy;
        for (auto it=froms.begin();it!=froms.end();) {
            if(it->second.size()==0) {
                canStudy.push_back(it->first);
                it=froms.erase(it);
            }
            else it++;
        }
        while (!canStudy.empty()) {
            int c=canStudy.back();
            canStudy.pop_back();
            vector<int> &courses=tos[c];
            for (auto course: courses) {
                froms[course].erase(c);
                if(froms[course].size()==0) {
                    canStudy.push_back(course);
                    froms.erase(course);
                }
            }
            tos.erase(c);
        }
        return froms.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_207_H
