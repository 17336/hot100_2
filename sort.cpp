//
// Created by 17336 on 2023/4/6.
//

#ifndef HOT100_2_SORT_H
#define HOT100_2_SORT_H

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Sort {
public:
    ListNode* sortList(ListNode* head) {

    }

    void quicksort(std::vector<int> &nums,int l,int r) {
        if(l<r) {
            int mid= partition(nums,l,r);
            quicksort(nums,l,mid-1);
            quicksort(nums,mid+1,r);
        }
    }

    int partition(std::vector<int> &nums,int l,int r) {
        int pilot=nums[l];
        while (l<r){
            while (l<r&&nums[r]>=pilot) --r;
            nums[l]=nums[r];
            while (l<r&&nums[l]<=pilot) ++l;
            nums[r]=nums[l];
        }
        nums[l]=pilot;
        return l;
    }
};

int main() {
    std::vector<int> nums{1,3,2,4,0,3,5,6,7,6,4,3,2,3,4,5};
    Sort s;
    s.quicksort(nums,0,nums.size()-1);
    for (const auto &item: nums) {
        std::cout<<item<<',';
    }
}

#endif //HOT100_2_SORT_H
