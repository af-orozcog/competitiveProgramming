#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1000000007;

vector<vector<int>> graph(500000);
int info[1000000];
ll dp[3][500000];

ll dfs(int w, int p){
    if(dp[w][p] != -1)
        return dp[w][p];
    if(graph[p].size() == 0)
        return 1;
    ll ans = 0;
    if((w == 1 && info[p] == 2) || (w == 2 && info[p] == 1)) ans = 0;
    else{
        if(w == 1)
            ans += (dfs(2,graph[p][0])*dfs(2,graph[p][1]))%M;
        else{
            ans += (dfs(1,graph[p][0])*dfs(1,graph[p][1]))%M;
            ans += (dfs(1,graph[p][0])*dfs(2,graph[p][1]))%M;
            ans += (dfs(2,graph[p][0])*dfs(1,graph[p][1]))%M;
        }
    }
    return dp[w][p] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf(" %d",&n);
    int tot = 0;
    for(int i = 0;i < n;++i){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        --a,--b;
        ++c;
        if(a != -1) graph[i].push_back(a);
        else {graph[i].push_back(n+tot);++tot;}
        if(b != -1) graph[i].push_back(b);
        else {graph[i].push_back(n+tot);++tot;}
        info[i] = c;
    }
    ll va = dfs(1,0);
    va += dfs(2,0);
    cout << va << "\n";
    ll wut = 1;
    for(int i = 0; i < tot;++i){
        wut <<= 1;
        wut = wut % M;
    }
    ll ans = wut - va;
    if(ans < 0) ans+= M;
    printf("%lld\n",ans);
    return 0;
}
