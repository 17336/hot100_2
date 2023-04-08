//
// Created by 17336 on 2023/4/7.
//

#ifndef HOT100_2_229_H
#define HOT100_2_229_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1,n2,count1=0,count2=0;
        for (int num:nums) {
            if(count1==0) {
                if(count2!=0&&n2==num) ++count2;
                else {
                    n1=num;
                    count1=1;
                }
            }
            else if(num==n1) ++count1;
            else if(count2==0) {
                n2=num;
                count2=1;
            }
            else if(num==n2) ++count2;
            else {
                count1--;
                count2--;
            }
        }
        vector<int> res;
        if(count1!=0 && isMajor(nums,n1)) res.push_back(n1);
        if(count2!=0 && isMajor(nums,n2)) res.push_back(n2);
        return res;
    }
    bool isMajor(vector<int>& nums,int num) {
        int count1=0;
        for (int i:nums) {
            if(i==num) ++count1;
        }
        return count1>nums.size()/3;
    }
};

#endif //HOT100_2_229_H
