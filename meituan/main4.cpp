#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n;
    std::vector<std::vector<int>> vecs(n,std::vector<int> (3,0));
    for (int i = 0; i < n; ++i) {
        std::cin>>vecs[i][0]>>vecs[i][1]>>vecs[i][2];
    }
    std::sort(vecs.begin(),vecs.end(),
              [](const std::vector<int> &a,const std::vector<int> &b)->bool {
                  return a[2]<b[2];
    });
    int res=0;

}