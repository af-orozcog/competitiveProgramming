#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort;
bitset<100005> seen;
int tr[100005];
void topo(int s,vector<vector<int>> &graph){
    if(seen[s])return;
    for(int i = 0; i < graph[s].size();++i)
        topo(graph[s][i],graph);
    seen[s] = 1;
    tr[s] = (int)topoSort.size();
    topoSort.push_back(s);
}

int dp[100005];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> graph(n);
    for(int i = 0; i < m;++i){
        int x,y;
        scanf(" %d %d",&x,&y);
        --x,--y;
        graph[x].push_back(y);
    }
    for(int i = 0; i < n;++i)
        topo(i,graph);
    int ans = 0;
    for(auto va:topoSort){
        for(auto ve:graph[va])
            dp[tr[va]] = max(dp[tr[va]],1+dp[tr[ve]]);
        ans = max(ans,dp[tr[va]]);
        //printf("who:%d ans:%d\n",va,dp[tr[va]]);
    }
    printf("%d\n",ans);
    return 0;
}
