#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,ll> pi;

vector<priority_queue<pi>> queriesSon(3*100000);
vector<priority_queue<pi>> queriesDad(3*100000);
int depth[3*100000];
ll finalVals[3*100000];

void dfs1(int p, int dad, int dep, vector<vector<int>> &g){
    depth[p] = dep;
    for(auto va:g[p])
        if(va != dad)
            dfs1(va,p,dep+1,g);
}

pair<ll,priority_queue<pi>> dfs2(int p, int dad,priority_queue<pi> &q,ll acum, vector<vector<int>> &g){
    while(q.size() && -q.top().first < depth[p]){
        acum -= q.top().second;
        q.pop();
    }
    finalVals[p] += acum;
    while(queriesSon[p].size()){
        acum += queriesSon[p].top().second;
        q.push(queriesSon[p].top());
        queriesSon[p].pop();
    }
    pair<ll,priority_queue<pi>> temp;
    temp.first = 0;
    for(auto va:g[p])
        if(va != dad){
            pair<ll,priority_queue<pi>> lel = dfs2(va,p,q,acum,g);
            temp.first += lel.first;
            while(lel.second.size() && lel.second.top().first > depth[p]){
                temp.first -= lel.second.top().second;
                lel.second.pop();
            }
        }
    finalVals[p] += temp.first;
    return temp;
}

int main(){
    int n,m;
    scanf(" %d",&n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(0,-1,0,g);
    scanf(" %d",&m);
    while(m--){
        int v,d; ll x;
        scanf(" %d %d %lld",&v,&d,&x);
        --v;
        queriesSon[v].push({-(depth[v]+d),x});
        finalVals[v] += x;
        queriesDad[v].push({depth[v],x});
    }
    priority_queue<pi> q;
    dfs2(0,-1,q,0ll,g);
    for(int i = 0; i < n;++i)
        printf("%lld ",finalVals[i]);
    puts("");
    return 0;
}
