#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int upTo = n*n;
    map<int,int> seen;
    for(int i = 0; i < upTo;++i){
        int va;
        scanf(" %d",&va);
        ++seen[va];
    }
    vector<int> ans;
    for(auto it = seen.rbegin(); it != seen.rend();++it){
        int now = (*it).first;
        while((*it).second != 0){
            for(auto va:ans){
                int lul = __gcd(now,va);
                seen[lul] -= 2;
            }
            if((*it).second != 0){
                ans.push_back(now);
                --seen[now];
            }
        }
    }
    for(auto va:ans)
        printf("%d ",va);
    printf("\n");
    return 0;
}
