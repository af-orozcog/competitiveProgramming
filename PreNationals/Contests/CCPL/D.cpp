#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;
ll INF = 1000000000000LL;

int n;
vector<vector<pi>> g;

vector<ll> cost;
vector<int> dad;

void dijsktra(){
    cost.clear();
    cost.resize(g.size(),INF);
    dad.clear();
    dad.resize(g.size(),-1);
    priority_queue<pi> q;
    q.push({0,0});
    cost[0] = 0;
    while(q.size()){
        pi check = q.top();
        q.pop();
        check.first *= -1;
        if(check.first > cost[check.second]) continue;
        for(auto adj:g[check.second]){
            if(check.first + adj.second < cost[adj.first]){
                cost[adj.first] = check.first + adj.second;
                q.push({-cost[adj.first],adj.first});
                dad[adj.first] = check.second;
            }
        }
    }
}

int main(){
    while(scanf(" %d",&n) && n){
        int m;
        scanf(" %d",&m);
        g.clear();
        g.resize(n);
        while(m--){
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            --a,--b;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        ll ans = 0;
        dijsktra();
        ans += cost.back();
        int from = n-1;
        while(dad[from] != -1){
            int to = dad[from];
            for(int i = 0; i < g[from].size();++i)
                if(g[from][i].first == to){
                    g[from][i].second *= -1;
                    break;
                }
            for(int i = 0; i < g[to].size();++i)
                if(g[to][i].first == from){
                    g[to].erase(g[to].begin()+i);
                    break;
                }
            from = dad[from];
        }
        dijsktra();
        ans += cost.back();
        if(ans >= INF)
            puts("Back to jail");
        else
            printf("%lld\n",ans);
    }
    return 0;
}
