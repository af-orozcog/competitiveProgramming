#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    vector<vector<int>> g(n);
    for(int i = 1; i < n;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dist[n];
    memset(dist,-1,sizeof(dist));
    ll count[2] = {0};
    count[0] = 1;
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()){
        int dad = q.front();
        q.pop();
        for(auto va:g[dad]){
            if(dist[va] == -1){
                dist[va] = (dist[dad]+1)&1;
                q.push(va);
                ++count[dist[va]];
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n;++i){
        int co[2] = {0};
        for(auto &va:g[i]) ++co[dist[va]];
        ans += count[(dist[i]+1)&1]-co[(dist[i]+1)&1];
    }
    printf("%lld\n",ans>>1);
    return 0;
}
