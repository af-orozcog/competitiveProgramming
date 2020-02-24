#include<bits/stdc++.h>
#define ll long long
#define MAXN 400000
using namespace std;

vector<vector<int>> graph(MAXN);
vector<int> extra(MAXN);
ll dp[3][MAXN];
ll visi[MAXN];
ll total = 0;
const ll M = 1000000007;

ll dfs(int n, int p){
    if(dp[n][p] != -1)return dp[n][p];
    if(graph[p].size() == 0){
        if(n != 0 && !visi[p])
            visi[p] = 1,--total;
        return dp[n][p] = 1;
    }
    dp[n][p] = 0ll;
    if(n == 0){
        if(!extra[p]){
            dp[n][p] = (dfs(2,graph[p][0]) * dfs(2,graph[p][1]))%M;
            dp[n][p] = (dp[n][p] + (dfs(2,graph[p][0]) * dfs(1,graph[p][1]))%M)%M;
            dp[n][p] = (dp[n][p] + (dfs(1,graph[p][0]) * dfs(2,graph[p][1]))%M)%M;
        }
        else if(extra[p] == -1)
            dp[n][p] = (dfs(0,graph[p][0]) * dfs(0,graph[p][1]))%M;
        else
            dp[n][p] = (dfs(1,graph[p][0]) * dfs(1,graph[p][1]))%M;
    }
    else if(n == 1){
        if(!extra[p]) return dp[n][p] = 0;
        else if(extra[p] == -1){
            dp[n][p] = (dfs(2,graph[p][0]) * dfs(2,graph[p][1]))%M;
            dp[n][p] = (dp[n][p] + (dfs(2,graph[p][0]) * dfs(1,graph[p][1]))%M)%M;
            dp[n][p] = (dp[n][p] + (dfs(1,graph[p][0]) * dfs(2,graph[p][1]))%M)%M;
        }
        else
            dp[n][p] = (dfs(1,graph[p][0]) * dfs(1,graph[p][1]))%M;
    }
    else{
        if(!extra[p]){
            dp[n][p] = (dfs(2,graph[p][0]) * dfs(2,graph[p][1]))%M;
            dp[n][p] = (dp[n][p] + (dfs(2,graph[p][0]) * dfs(1,graph[p][1]))%M)%M;
            dp[n][p] = (dp[n][p] + (dfs(1,graph[p][0]) * dfs(2,graph[p][1]))%M)%M;
        }
        else if(extra[p] == -1)
            dp[n][p] = (dfs(1,graph[p][0]) * dfs(1,graph[p][1]))%M;
        else
            return dp[n][p] = 0;
    }
    return dp[n][p];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        --a,--b;
        if(a != -1) graph[i].push_back(a);
        else {graph[i].push_back(n+total);++total;}
        if(b != -1) graph[i].push_back(b);
        else{graph[i].push_back(n+total);++total;}
        extra[i] = c;
    }
    ll val = dfs(0,0);
    cout << val << endl;
    ll ans = (val * (1<<total))%M;
    printf("%lld\n",ans);
    return 0;
}
