#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll INF = 1000000000000000000ll;

int main(){
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    vector<vector<pair<int,ll>>> g(n);
    for(int i = 0; i < m;++i){
        int a,b,l;
        scanf(" %d %d %d",&a,&b,&l);
        --a,--b;
        g[a].push_back({b,l});
        g[b].push_back({a,l});
    }
    if(k == 0){
        puts("-1");
        return 0;
    }
    int from[k];
    priority_queue<pair<ll,int>> q;
    vector<ll> dist(n,INF);
    for(int i = 0; i < k;++i){
        scanf(" %d",&from[i]);
        --from[i];
        q.push({0ll,from[i]});
        dist[from[i]] = 0;
    }
    while(q.size()){
        ll di = -q.top().first;
        int from = q.top().second;
        q.pop();
        if(dist[from] < di) continue;
        for(auto va:g[from]){
            if(di + va.second < dist[va.first]){
                dist[va.first] = di+va.second;
                q.push({-dist[va.first],va.first});
            }
        }
    }
    ll ans = INF;
    for(auto va: dist){
        if(va > 0)
            ans = min(va,ans);
    }
    if(ans == INF)
        puts("-1");
    else
        printf("%lld\n",ans);
    return 0;
}
