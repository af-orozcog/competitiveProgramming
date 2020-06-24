#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int ans;
int anW;

int dfs(int p, int dad,vector<vector<int>> &graph, vector<int> &dp){
    int ans = 1;
    for(int i = 0; i < graph[p].size();++i)
        if(graph[p][i] != dad)
            ans += dfs(graph[p][i],p,graph,dp);
    return dp[p] = ans;
}

void dfs2(int p, int dad,vector<vector<int>> &graph, vector<int> &dp){
    int n = graph.size();
    int an = n - dp[p];
    for(int i = 0; i < graph[p].size();++i){
        if(graph[p][i] != dad){
            an = max(an,dp[graph[p][i]]);
            dfs2(graph[p][i],p,graph,dp);
        }
    }
    int comp = an;
    if(ans > comp) ans = comp, anW = p+1;
    return;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ans = 1000000000;
        vector<int> dp(n,0);
        vector<vector<int>> graph(n);
        for(int i = 0; i < n-1;++i){
            int a,b;
            scanf(" %d %d",&a,&b);
            --a,--b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int who;
        for(int i = 0; i < n;++i){
            if(graph[i].size() == 1){who = i;break;}
        }
        dfs(who,-1,graph,dp);
        //cout << "wut" << "\n";
        dfs2(who,-1,graph,dp);
        printf("%d %d\n",anW,ans);
    }
    return 0;
}
