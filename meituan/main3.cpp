#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n,t;
    std::cin>>n>>t;
    std::vector<int> roads(n,0);
    for (int i = 0; i < t; ++i) {
        char c;
        int x;
        std::cin>>c>>x;
        if(c=='Q') {
            int l=x,r=x;
            while (l>1&&roads[l-1]) {
                l-=1;
            }
            while (r<n&&roads[r]) ++r;
            std::cout<<l<<' '<<r<<std::endl;
        }
        else if(c=='L') {
            if(x>1) roads[x-1]=1;
        }
        else {
            if(x<n) roads[x]=1;
        }
    }
    return 0;
}