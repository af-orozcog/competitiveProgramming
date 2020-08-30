#include<bits/stdc++.h>
#define ll long long
using namespace std;

int seen[100005];
ll C[100005];
vector<vector<int>> g;

ll dfs(int p){
    seen[p] = 1;
    ll ans = C[p];
    for(auto va: g[p])
        if(seen[va] == -1)
            ans = min(ans,dfs(va));
    return ans;
}

int main(){
    int n,m;
    memset(seen,-1,sizeof(seen));
    scanf(" %d %d",&n,&m);
    for(int i = 0; i < n;++i) scanf(" %lld",&C[i]);
    g.resize(n);
    for(int i = 0; i < m;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 0;
    for(int i = 0; i < n;++i)
        if(seen[i] == -1)
            ans += dfs(i);
    printf("%lld\n",ans);
    return 0;
}
