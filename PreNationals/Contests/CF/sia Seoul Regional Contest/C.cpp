#include<bits/stdc++.h>
using namespace std;

int ans = 0;

vector<vector<int>> gP;
vector<vector<int>> g;
set<int> apartments;
vector<int> dp;

int dfs(int p, int dad){
    int kids = apartments.count(p);
    for(auto adj:g[p]){
        if(adj != dad){
            gP[p].push_back(adj);
            kids += dfs(adj,p);
        }
    }
    return dp[p] = kids;
}

bool valid(int p){
    if(apartments.count(p)) return 1;
    int kids = 0;
    for(auto adj:gP[p]){
        kids += (dp[adj] > 0);
    }
    if(kids >= 2) return 1;
    if(dp[p] == 0) return 0;
    return dp[0]-dp[p] > 0;
}

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    gP.resize(n);
    g.resize(n);
    dp.resize(n,0);
    for(int i = 0; i < n-1;++i){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < k;++i){
        int va;
        scanf(" %d",&va);
        --va;
        apartments.insert(va);
    }
    dfs(0,-1);
    for(int i = 0; i < n;++i){
        ans += valid(i);
    }
    printf("%d\n",ans);
    return 0;
}
