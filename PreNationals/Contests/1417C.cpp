#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        map<int,vector<int>> mp;
        int ans[n+1];
        memset(ans,-1,sizeof(ans));
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            mp[va].push_back(i);
        }

        int top = n+1;
        for(auto &va:mp){
            int left = -1;
            int mi = 1;
            for(auto ind:va.second){
                mi = max(mi,ind-left);
                left = ind;
            }
            mi = max(mi,n-left);
            for(int i = mi; i < top;++i) ans[i] = va.first;
            top = min(top,mi);
        }

        for(int i = 1; i <= n;++i) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
