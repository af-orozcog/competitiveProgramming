#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> br;
vector<vector<int>> adj;
vector<int> ap, low,disc;
vector<int> toConnect;
int Time;
void dfsBR(int u, int p) {
  low[u] = disc[u] = ++Time;
  for (int& v : adj[u]) {
    if (v == p) continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
    if (!disc[v]) { // if V has not been discovered before
      dfsBR(v, u);  // recursive DFS call
      if (disc[u] < low[v]) // condition to find a bridge
        br.insert({min(u,v), max(v,u)});
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    } else // if v was already discovered means that we found an ancestor
      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
  }
}

void BR() {
  low = disc = vector<int>(adj.size());
  Time = 0;
  for (int u = 0; u < adj.size(); u++)
    if (!disc[u]){
      dfsBR(u, u);
      toConnect.push_back(u);
    }
}

vector<unordered_set<int>> g;

void dfs1(int color, int p){
    disc[p] = color;
    for(auto va: adj[p])
        if(disc[va] == -1 && !br.count({min(p,va),max(p,va)}))
            dfs1(color,va);
}

int l;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : g[v]) {
        if (u != p)
            dfs(u, v);
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

void preprocess(int root,int n) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

vector<int> height;
void dfsHeight(int p, int dad, int h){
    height[p] = h;
    for(auto va:g[p]){
        if(va != dad)
            dfsHeight(va,p,h+1);
    }
}

int dist(int a,int b){
    return height[a] + height[b] - 2*height[lca(a,b)];
}

int main(){
    int n,m,q;
    scanf(" %d %d",&n,&m);
    adj.resize(n);
    ap = low = disc = vector<int>(adj.size());
    for(int i = 0; i < m;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BR();
    fill(disc.begin(),disc.end(),-1);
    int color = 1;
    for(int i = 0; i < n;++i){
        if(disc[i] == -1){
            dfs1(color,i);
            ++color;
        }
    }
    g.resize(color);
    for(auto va:toConnect){
        g[0].insert(disc[va]);
        g[disc[va]].insert(0);
    }
    height.resize(color);
    for(int i = 0; i < n;++i){
        for(auto va:adj[i]){
            if(br.count({min(i,va),max(i,va)})){
                g[disc[i]].insert(disc[va]);
                g[disc[va]].insert(disc[i]);
            }
        }
    }
    preprocess(0,g.size());
    dfsHeight(0,0,0);
    scanf(" %d",&q);
    while(q--){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        printf("%d\n",dist(disc[a],disc[b])+2);
    }
    return 0;
}
