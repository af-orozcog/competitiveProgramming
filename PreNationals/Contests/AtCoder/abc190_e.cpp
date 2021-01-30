#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> overAll;
int dp[17][(1<<17)-1];

vector<int> bfs(int from, vector<vector<int>> &g){
    vector<int> dist(g.size(),-1);
    queue<int> q;
    q.push(from);
    dist[from] = 0;
    while(q.size()){
        int dad = q.front();
        q.pop();
        for(auto adj:g[dad]){
            if(dist[adj] == -1){
                dist[adj] = dist[dad]+1;
                q.push(adj);
            }
        }
    }
    return dist;
}

int solve(int p, int mask,int n,int who[]){
    if(mask == (1<<n)-1) return 0;
    if(dp[p][mask] != -1) return dp[p][mask];
    int ans = 1000000000;
    for(int i = 0; i < n;++i){
        if(((mask>>i)&1) || overAll[p][who[i]] == -1) continue;
        ans = min(ans,solve(i,mask | (1<<i),n,who)+overAll[p][who[i]]);
    }
    return dp[p][mask] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> g(n);
    while(m--){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k;
    scanf(" %d",&k);
    int who[k];
    for(int i = 0; i < k;++i){
        scanf(" %d",&who[i]);
        --who[i];
    }
    overAll.resize(k);
    int ans = 1000000000;
    for(int i = 0; i < k;++i)
        overAll[i] = bfs(who[i],g);
    for(int i = 0; i < k;++i)
        ans = min(ans,solve(i,(1<<i),k,who));

    if(ans == 1000000000) puts("-1");
    else printf("%d\n",ans+1);
    return 0;
}
