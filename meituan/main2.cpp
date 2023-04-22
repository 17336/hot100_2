//
// Created by 17336 on 2023/4/15.
//

#include <iostream>
#include <vector>
#include <climits>

void func(int n,int a,int b) {
    int x1=a*n/(a+b),x2=(a*n/(a+b)+1);
    if(x1==0) x1=1;
    if(x2==n) x2=n-1;
    int res=INT_MAX;
    res=std::max(std::min(a/x1,b/(n-x1)),std::min(a/x2,b/(n-x2)));
    std::cout<<res<<std::endl;
}

int main() {
    int t;
    std::cin>>t;
    for (int i = 0; i < t; ++i) {
        int n,a,b;
        std::cin>>n>>a>>b;
        func(n,a,b);
    }
    return 0;
}
