#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

ll dist[3][100005];

void dijsktra(vector<int> &sources,vector<vector<int>> &graph,int index){
    priority_queue<pi> q;
    for(int i = 0; i < sources.size();++i){
        dist[index][sources[i]] = 0;
        q.push({0,-sources[i]});
    }
    while(q.size()){
        pi see = q.top();
        q.pop();
        if(dist[index][-see.second] < -see.first) continue;
        for(auto adj:graph[-see.second]){
            if(-see.first + 1 < dist[index][adj]){
                q.push({see.first-1,-adj});
                dist[index][adj] = -see.first + 1;
            }
        }
    }
}

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i)
        dist[0][i] = dist[1][i] = dist[2][i] = 1000000000;
    vector<vector<int>> graph(n);
    vector<vector<int>> invertedGraph(n);
    int m,k;
    scanf(" %d %d",&m,&k);
    vector<int> iron(m);
    vector<int> coal(k);
    vector<int> init;
    init.push_back(0);
    for(int i = 0; i < m;++i){
        scanf(" %d",&iron[i]);
        --iron[i];
    }
    for(int i = 0; i < k;++i){
        scanf(" %d",&coal[i]);
        --coal[i];
    }
    for(int i = 0; i < n;++i){
        int j;
        scanf(" %d",&j);
        while(j--){
            int neig;
            scanf(" %d",&neig);
            --neig;
            graph[i].push_back(neig);
            invertedGraph[neig].push_back(i);
        }
    }
    ll ans = 1000000000;
    dijsktra(iron,invertedGraph,0);
    dijsktra(coal,invertedGraph,1);
    dijsktra(init,graph,2);
    for(int i = 0; i < n;++i){
        ll see = dist[0][i] + dist[1][i] + dist[2][i];
        ans = min(ans,see);
    }
    if(ans == 1000000000ll) puts("impossible");
    else printf("%lld\n",ans);
    return 0;
}
