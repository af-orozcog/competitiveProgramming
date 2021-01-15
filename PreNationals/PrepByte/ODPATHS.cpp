#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int n, l;
vector<vector<int>> adj;
vector<vector<int>> cost;
vector<bool> parity;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p,int par)
{
    parity[v] = par;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int i = 0; i < adj[v].size();++i) {
        int u = adj[v][i];
        if (u != p)
            dfs(u, v,(par+(cost[v][i]%2))%2);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root,0);
}



int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %d",&n);
        adj.clear();
        tin.clear();
        tout.clear();
        up.clear();
        cost.clear();
        adj.resize(n);
        cost.resize(n);
        parity.resize(n);
        for(int i = 0; i < n-1;++i){
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            --a,--b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        preprocess(0);
        int q;
        scanf(" %d",&q);
        while(q--){
            int a,b;
            scanf(" %d %d",&a,&b);
            --a,--b;
            int who = lca(a,b);
            int val = ((parity[who]^parity[a]) + (parity[who]^parity[b]))&1;
            if(val) puts("ODD PATH");
            else puts("EVEN PATH");
        }
    }
    return 0;
}
