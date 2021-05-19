#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

vector<int> colors;

bool dfs(int n, int color, vector<vector<int>> &g){
    colors[n] = color;
    bool ans = 1;
    for(auto adj: g[n]){
        if(colors[adj] == -1)
            ans = dfs(adj,(color+1)%2,g);
        else if(colors[adj] == colors[n]) ans = 0;
        if(!ans) break;
    }
    return ans;
}

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
    colors.resize(n,-1);
    ll ans = 0;
    for(int i = 0; i < (1<<n);++i){
        fill(colors.begin(),colors.end(),-1);
        for(int j = 0, temp = i; j < n;++j){
            if(temp&1) colors[j] = 2;
            temp >>= 1;
        }
        bool posi = 1;
        for(int j = 0; j < n && posi;++j){
            if(colors[j] == 2){
                for(auto adj:g[j]){
                    if(colors[j] == colors[adj])
                        posi = 0;
                }
            }
        }
        int con = 0;
        for(int j = 0; j < n && posi;++j){
            if(colors[j] == -1){
                posi = dfs(j,0,g);
                ++con;
            }
        }
        if(posi)
            ans += 2;
    }
    printf("%lld\n",ans);
    return 0;
}
