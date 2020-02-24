#include<bits/stdc++.h>
using namespace std;

int maxx, who;

void dfs(int p, int dad, int dist, vector<vector<int>> &graph){
    int neDist = dist + 1;
    for(int i = 0; i < graph[p].size();++i){
        if(graph[p][i] != dad)
            dfs(graph[p][i],p,neDist,graph);
    }
    if(neDist >  maxx){
        maxx = neDist;
        who = p;
    }
}

int main(){
    int n;
    scanf(" %d",&n);
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1;++i){
        int a,b; scanf(" %d %d",&a,&b);
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0,-1,-1,graph);
    dfs(who,-1,-1,graph);
    printf("%d\n",maxx);
    return 0;
}
