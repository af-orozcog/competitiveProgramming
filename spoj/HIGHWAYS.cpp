#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m,s,t;
        scanf(" %d %d %d %d",&n,&m,&s,&t);
        --s,--t;
        vector<vector<pair<int,int>>> graph(n);
        while(m--){
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            --a,--b;
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
        vector<int> dist(n,2000000000);
        dist[s] = 0;
        priority_queue<pair<int,int>> q;
        q.push({0,s});
        while(q.size()){
            int f1 = -q.top().first,f2 = q.top().second; q.pop();
            if(dist[f2] < f1) continue;
            for(int i = 0; i < graph[f2].size();++i){
                if(graph[f2][i].second + dist[f2] < dist[graph[f2][i].first]){
                    dist[graph[f2][i].first] = graph[f2][i].second + dist[f2];
                    q.push({-dist[graph[f2][i].first],graph[f2][i].first});
                }
            }
        }
        if(dist[t] != 2000000000) printf("%d\n",dist[t]);
        else puts("NONE");
    }
    return 0;
}
