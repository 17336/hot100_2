//
// Created by 17336 on 2023/4/5.
//

#ifndef HOT100_2_139_H
#define HOT100_2_139_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Tire{
public:
    bool end;
    vector<Tire *> next;
public:
    Tire():end(false),next(26, nullptr){};
    void insert(const string &word) {
        Tire *p=this;
        for (auto c:word) {
            if(!p->next[c-'a'])
                p->next[c-'a']=new Tire();
            p=p->next[c-'a'];
        }
        p->end= true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Tire *t=new Tire();
        for (auto &word:wordDict) {
            t->insert(word);
        }
        unordered_map<int,bool> dps;
        return backtrace(s,0,t,dps);
    }

    bool backtrace(const string &s, int begin, Tire *t, unordered_map<int,bool> &dps) {
        if(begin==s.size()) return true;
        if(dps.find(begin)!=dps.end()) return dps[begin];
        int i=begin;
        Tire *p=t;
        while (i<s.size()) {
            char c=s[i];
            if(p->next[c-'a']) {
                p=p->next[c-'a'];
            }
            else break;
            if(p->end && backtrace(s,i+1,t,dps)) return true;
            ++i;
        }
        dps[begin]= false;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_139_H
