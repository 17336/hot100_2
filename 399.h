//
// Created by 17336 on 2023/4/16.
//

#ifndef HOT100_2_399_H
#define HOT100_2_399_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, unordered_map<string, double>> m;
        int len = equations.size();
        for (int i = 0; i < len; ++i) {
            string &a = equations[i][0];
            string &b = equations[i][1];
            m[a][b] = values[i];
            m[b][a] = 1 / values[i];
        }
        vector<double> res;
        for (auto &item:queries) {
            double path=1.0;
            unordered_set<string> s;
            if(dfs(m,item[0],item[1],s,path)) res.push_back(path);
            else res.push_back(-1.0);
        }
        return res;
    }

    bool dfs(unordered_map<string, unordered_map<string, double>> &m,
               const string &a, const string &b, unordered_set<string> &s,double &path) {
        if(m.find(a)==m.end()) return false;
        if(m[a].find(b)!=m[a].end()) {
            path*=m[a][b];
            return true;
        }
        if (a == b) return true;
        for(auto &item:m[a]) {
            if(s.find(item.first)==s.end()){
                s.insert(item.first);
                path*=item.second;
                if(dfs(m,item.first,b,s,path)) return true;
                path/=item.second;
                s.erase(item.first);
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_399_H
