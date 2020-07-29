#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 400*6
typedef pair<int,ll> pi;


ll dist[MAXN];
ll dad[MAXN];

void dijsktra(vector<int> &sources, vector<vector<pi>> &g){
    priority_queue<pi> q;
    for(auto va:sources){
        dist[va] = 0;
        q.push({0,va});
        dad[va] = -1;
    }
    while(q.size()){
        pi see = q.top();
        q.pop();
        if(dist[see.second] < -see.first) continue;
        for(auto va:g[see.second]){
            if(dist[va.first] > dist[see.second] + va.second){
                dad[va.first] = see.second;
                dist[va.first] = dist[see.second] + va.second;
                q.push({-dist[va.first],va.first});
            }
        }
    }
}

int multi(string &see){
    if(see == "AIR")
        return 0;
    else if(see == "SEA")
        return 1;
    else if(see == "RAIL")
        return 2;
    return 3;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        for(int i = 0; i < MAXN;++i)
        dist[i] = 100000000000000ll;
        unordered_map<string,int> fr;
        int n;
        cin >> n;
        vector<vector<pi>> g(MAXN);
        for(int i = 0; i < n;++i){
            string city; ll cost;cin >> city >> cost;
            fr[city] = i;
            for(int j = 0; j < 4;++j){
                for(int k = j+1;k < 4;++k){
                    g[n*j+i].push_back({n*k+i,cost});
                    g[n*k+i].push_back({n*j+i,cost});
                }
            }
        }
        int m;
        cin >> m;
        while(m--){
            string from,to, type;
            ll cost;
            cin >> from >> to >> type >> cost;
            int f = fr[from],tt = fr[to];
            int t = multi(type);
            g[t*n+f].push_back({t*n+tt,cost});
            g[t*n+tt].push_back({t*n+f,cost});
        }
        string from,to;
        cin >> from >> to;
        vector<int> sources;
        for(int i = 0; i < 4;++i)
            sources.push_back(i*n+fr[from]);
        dijsktra(sources,g);
        ll ans = 1000000000000ll;
        int who;
        for(int i = 0; i < 4;++i){
            if(dist[i*n+fr[to]] < ans)
                who = i*n+fr[to],ans = dist[i*n+fr[to]];
        }
        /*vector<int> route;
        route.push_back(who);
        while(dad[who] != -1){

        }*/
        cout << ans << "\n";
    }
    return 0;
}
