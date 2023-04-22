//
// Created by 17336 on 2023/4/13.
//

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>

int main() {
    int n,v;
    std::cin>>n>>v;
    std::vector<int> vs(n),ws(n);
    for (int i = 0; i < n; ++i) {
        std::cin>>vs[i]>>ws[i];
    }
    std::vector<int> dps(v+1,0);
    for (int i = 0; i < n; ++i) {
        for (int j = v; j >= vs[i]; --j) {
            dps[j]=std::max(dps[j-vs[i]]+ws[i],dps[j]);
        }
    }
    std::cout<<dps[v];
    return 0;
}



