#include <vector>
#include <string>
#include <iostream>

void func(std::string &s,std::string &t) {
    int len1=s.size(),len2=t.size();
    int res=0;
    if(len1>len2) res=len1-len2;
    int i=std::min(len1,len2)-1;
    while (i>=0) {
        if(s[i]!=t[i]) ++res;
        --i;
    }
    std::cout<<res<<std::endl;
}

int main() {
    int n;
    std::cin>>n;
    std::string s,t;
    for (int i = 0; i < n; ++i) {
        std::cin>>s>>t;
        func(s,t);
    }
    return 0;
}