#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> g(n);
    for(int i = 0; i < m;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dist[n];
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()){
        int dad = q.front();
        q.pop();
        for(auto va:g[dad]){
            if(dist[va] == -1){
                dist[va] = dist[dad]+1;
                q.push(va);
            }
        }
    }
    if(dist[n-1] != -1 && dist[n-1] < 3)
        puts("POSSIBLE");
    else
        puts("IMPOSSIBLE");
    return 0;
}
