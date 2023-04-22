#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n;
    std::cin>>n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin>>nums[i];
    }
    std::sort(nums.begin(),nums.end());
    int i=0,x=0,could=0;
    while (i<n) {
        if(nums[i]==x){
            x+=1;
        }
        else if(nums[i]<x) could++;
        else if(could>=nums[i]-x) {
            could-=nums[i]-x;
            x=nums[i]+1;
        }
        else {
            break;
        }
        ++i;
    }
    if(could) x+=could;
    std::cout<<x;
    return 0;
}