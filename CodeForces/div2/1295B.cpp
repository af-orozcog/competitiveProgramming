#include<bits/stdc++.h>
using namespace std;

int modulo(int x, int y){
    int va = x % y;
    if(va < 0) return (x %y)+y;
    return va;
}

int main(){
    int t;
    scanf(" %d",&n);
    while(t--){
        int n, x;
        scanf(" %d %d",&n,&x);
        char see[n+1];
        scanf(" %s",see);
        int pre[n];
        vector<bool> seen(n,false);
        unordered_map<int,set<int>> dp;
        int be = n-1;
        for(int i = 0; i < n;++i){
            if(i == 0)
                pre[i] = (see[i] == '1'?-1:1);
            else
                pre[i] = pre[i-1] + (see[i] == '1'?-1:1);
            if(pre[i] == x)
                be = min(be,i);
            dp[pre[i]].insert(i);
        }
        if(pre[be] == x) seen[be] = 1;

    }
}
