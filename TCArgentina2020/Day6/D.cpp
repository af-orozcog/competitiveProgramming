#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

vector<pi> possible(int f,int bigger, vector<vector<pi>> &g){
    vector<pi> ans;
    for(auto va:g[f]){
        if(va.second > bigger)
            ans.push_back({va.first,va.second});
    }
    return ans;
}

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<pi>> g(n);
    vector<pair<int,pi>> edges(m);
    for(int i = 0; i < m;++i){
       int a,b,c;
       scanf(" %d %d %d",&a,&b,&c);
       --a,--b;
       g[a].push_back({b,c});
       edges[i] ={c,{a,b}};
    }
    map<pi,int> dp;
    sort(edges.begin(),edges.end());
    int ans = 0;
    for(int i = m-1; i > -1;--i){
        pair<int,pi> see = edges[i];
        vector<pi> wut = possible(see.second.second,see.first,g);
        dp[{see.second.first,see.second.second}] = 1;
        for(auto va:wut){
            int a = see.second.second,b = va.first;
            dp[{see.second.first,see.second.second}] = max(1 + dp[{a,b}],dp[{see.second.first,see.second.second}]);
        }
        ans = max(ans,dp[{see.second.first,see.second.second}]);
    }
    printf("%d\n",ans);
    return 0;
}
