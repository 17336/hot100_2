//
// Created by 17336 on 2023/4/10.
//

#ifndef HOT100_2_208_H
#define HOT100_2_208_H

#include <vector>
#include <string>


//leetcode submit region begin(Prohibit modification and deletion)
class Trie {
    std::vector<Trie *> next;
    bool end;
public:
    Trie():end(false),next(26, nullptr) {

    }

    void insert(std::string word) {
        Trie *p=this;
        for(auto c:word) {
            if(!p->next[c-'a']) p->next[c-'a']=new Trie();
            p=p->next[c-'a'];
        }
        p->end= true;
    }

    bool search(std::string word) {
        Trie *p=this;
        for(auto c:word) {
            if(!p->next[c-'a']) return false;
            p=p->next[c-'a'];
        }
        return p->end;
    }

    bool startsWith(std::string prefix) {
        Trie *p=this;
        for(auto c:prefix) {
            if(!p->next[c-'a']) return false;
            p=p->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_208_H
