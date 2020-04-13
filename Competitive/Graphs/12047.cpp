#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,m,s,ta,p;
        scanf(" %lld %lld %lld %lld %lld",&n,&m,&s,&ta,&p);
        vector<vector<pi>> graph1(n),graph2(n);
        vector<pair<ll,pi>> edges;
        --s,--ta;
        for(int i = 0; i < m;++i){
            ll f,t,c;
            scanf(" %lld %lld %lld",&f,&t,&c);
            --f,--t;
            graph1[f].push_back({t,c});
            graph2[t].push_back({f,c});
            edges.push_back({c,{f,t}});
        }
        vector<ll> dist1(n,1000000000),dist2(n,1000000000);
        priority_queue<pi> q;
        q.push({0,s});
        dist1[s] = 0;
        dist2[ta] = 0;
        while(q.size()){
            int f1 = -q.top().first, f2 = q.top().second;
            q.pop();
            if(dist1[f2] < f1) continue;
            for(int i = 0; i < graph1[f2].size();++i){
                if(f1 + graph1[f2][i].second < dist1[graph1[f2][i].first]){
                    dist1[graph1[f2][i].first] = f1 + graph1[f2][i].second;
                    q.push({-dist1[graph1[f2][i].first],graph1[f2][i].first});
                }
            }
        }
        q.push({0,ta});
        while(q.size()){
            int f1 = -q.top().first, f2 = q.top().second;
            q.pop();
            if(dist2[f2] < f1) continue;
            for(int i = 0; i < graph2[f2].size();++i){
                if(f1 + graph2[f2][i].second < dist2[graph2[f2][i].first]){
                    dist2[graph2[f2][i].first] = f1 + graph2[f2][i].second;
                    q.push({-dist2[graph2[f2][i].first],graph2[f2][i].first});
                }
            }
        }
        ll ans = -1;
        for(auto &va: edges){
            //cout << va.first << " " << dist1[va.second.first] + va.first + dist2[va.second.second] << endl;
            if(dist1[va.second.first] + va.first + dist2[va.second.second] <= p)
                ans = max(ans,va.first);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
