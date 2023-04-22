//
// Created by 17336 on 2023/4/13.
//

#ifndef HOT100_2_BAG_H
#define HOT100_2_BAG_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int bag_01(std::vector<int> vs, std::vector<int> ws, int v) {
    std::vector<int> dps(v + 1, 0);
    int n = vs.size();
    for (int i = 0; i < n; ++i) {
        for (int j = v; j >= vs[i]; --j) {
            dps[j] = std::max(dps[j - vs[i]] + ws[i], dps[j]);
        }
    }
    return dps[v];
}

int bag_wanquan(std::vector<int> &vs, std::vector<int> &ws, int v) {
    std::vector<int> dps(v+1,0);
    int n=vs.size();
    for (int i = 0; i < n; ++i) {
        for (int j = vs[i]; j <= v; ++j) {
            dps[j]= std::max(dps[j],dps[j-vs[i]]+ws[i]);
        }
    }
    return dps[v];
}

#endif //HOT100_2_BAG_H
