#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int n,m,k,s,t;

pi intersect(pi f, pi s){
    pi ans;
    if(f.second >= s.first || s.second >= f.first){
        ans.first = max(f.first,s.first);
        ans.second = min(f.second,s.second);
        return ans;
    }
    return {0,-1};
}


vector<pi> pos;

void dfs(int from, int to,vector<bool> &visited,vector<vector<pair<int,pi>>> &graph, pi act){
    visited[from] = 1;
    if(from == to){
        if(act.first != 0) pos.push_back(act);
        visited[from] = 0;
        return;
    }
    for(auto va: graph[from]){
        if(!visited[va.first])
            dfs(va.first,to,visited,graph,intersect(va.second,act));
    }
    visited[from] = 0;
}

int main(){
    scanf(" %d %d %d %d %d",&n,&m,&k,&s,&t);
    --s,--t;
    vector<vector<pair<int,pi>>> graph(n);
    while(m--){
        int a,b,c,d;
        scanf(" %d %d %d %d",&a,&b,&c,&d);
        --a,--b;
        graph[a].push_back({b,{c,d}});
    }
    vector<bool> visited(n,0);
    dfs(s,t,visited,graph,{0,1000000004});
    sort(pos.begin(),pos.end());
    int ans = 0;
    int l = pos[0].first;
    int r = pos[0].second;
    for(auto va: pos){
        if(va.first <= r) r = va.second;
        else {
            ans += r-l+1;
            l = va.first;
            r = va.second;
        }
    }
    ans += r-l+1;
    printf("%d\n",ans);
    return 0;
}
