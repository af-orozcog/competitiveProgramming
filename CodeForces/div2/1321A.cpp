#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    set<int> ar1;
    int sum1 = 0;
    int ad = 0;
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        if(va) ar1.insert(i);
    }
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        if(va){
            if(!ar1.count(i)) ++sum1;
            else ar1.erase(i);
        }
    }
    ++sum1;
    int ans = 1;
    if(sum1 && ar1.size())
        ans = sum1/(int)ar1.size() + (sum1%(int)ar1.size() != 0);
    else if(sum1 && !ar1.size())
        ans = -1;
    printf("%d\n",ans);
    return 0;
}
