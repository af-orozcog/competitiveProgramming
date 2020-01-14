#include<bits/stdc++.h>
using namespace std;

int dp[200000];

int dfs(int p, int dad, vector<vector<pair<int,int>>> &graph){
    for(int i = 0; i < graph[p].size();++i){
        if(graph[p][i].first != dad)
            dp[p] += dfs(graph[p][i].first,p,graph) + graph[p][i].second;
    }
   // cout << dp[p] << endl;
    return dp[p];
}

void lel(int p, int dad, vector<vector<pair<int,int>>> &graph, int su){
    dp[p] = dp[dad] + su;
     for(int i = 0; i < graph[p].size();++i){
        if(graph[p][i].first != dad)
            lel(graph[p][i].first, p, graph,(graph[p][i].second == 1? -1:1));
    }
}

int main(){
    int n;
    scanf(" %d",&n);
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0; i < n-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a;--b;
        graph[a].push_back({b,0});
        graph[b].push_back({a,1});
    }
    dfs(0,-1,graph);
    for(int i = 0; i < graph[0].size();++i){
        lel(graph[0][i].first, 0, graph,(graph[0][i].second == 1? -1:1));
    }
    int mi = 1000000000;
    vector<int> ans;
    for(int i = 0; i < n;++i){
        if(dp[i] < mi){
            ans.clear();
            ans.push_back(i);
            mi = dp[i];
        }
        else if(dp[i] == mi) ans.push_back(i);
    }
    printf("%d\n",mi);
    for(auto va:ans) printf("%d ",va+1);
    puts("");
    return 0;
}
