//
// Created by 17336 on 2023/4/6.
//

#ifndef HOT100_2_146_H
#define HOT100_2_146_H

#include <unordered_map>

//leetcode submit region begin(Prohibit modification and deletion)
struct Lnode{
public:
    int key_;
    int val_;
    Lnode *next_;
    Lnode *pre_;
    Lnode(int key,int val):key_(key),val_(val),next_(nullptr),pre_(nullptr) {}
    Lnode():val_(0),next_(nullptr),pre_(nullptr) {}
};

class LRUCache {
    // get(key) 要求O(1)，说明一定有哈希表结构
    // 逐出 最久未使用的关键字要求O(1)，则使用顺序是顺序表了，
    // 比如1,3,4,5，且O(1)修改节点顺序比如将3移到最后1,4,5,3，链表移动为O(1)。
    std::unordered_map<int,Lnode *> map;
    Lnode *first;
    Lnode *end;
    int cap;
public:
    LRUCache(int capacity):cap(capacity) {
        first=new Lnode(-1,-1);
        end=first;
    }

    int get(int key) {
        if(map.find(key)==map.end()) return -1;
        Lnode *t=map[key];
        return up(t);
    }

    void put(int key, int value) {
        if(map.find(key)!=map.end()) {
            Lnode *t=map[key];
            t->val_=value;
            up(t);
            return;
        }
        if(map.size()>=cap) {
            Lnode*t=first->next_;
            map.erase(t->key_);
            t->key_=key;
            t->val_=value;
            up(t);
            map[key]=t;
            return;
        }
        Lnode *t=new Lnode(key,value);
        t->pre_=end;
        end->next_=t;
        end=t;
        map[key]=t;
    }
    
    int up(Lnode *t) {
        if(t==end) return t->val_;
        t->pre_->next_=t->next_;
        t->next_->pre_=t->pre_;
        end->next_=t;
        t->pre_=end;
        t->next_= nullptr;
        end=t;
        return t->val_;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2_146_H
