#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000007;
int colors[100002];

pair<ll,ll> solve(int p, vector<vector<int>> &g){
    if(!g[p].size()){
        if(colors[p]) return {1,0};
        else return {0,1};
    }
    pair<ll,ll> temp[(int)g[p].size()];
    for(int i = 0; i < g[p].size();++i)
        temp[i] = solve(g[p][i],g);
    if((int)g[p].size() == 1){
        if(colors[p]){
            if(temp[0].first)
                return {(temp[0].first*(temp[0].second+1ll))%mod,0};
            else if(temp[0].second)
                return {1,0};
        }else
            return {temp[0].first,temp[0].second+1ll};
    }
    pair<ll,ll> ans;
    for(int i = 0; i < g[p].size();++i){
        for(int j = i+1; j <g[p].size();++j){
            if()
        }
    }
    if(colors[p])ans.second = 0;
    else ans.second = 1;
    return ans;
}


int main(){
    int n;
    scanf(" %d",&n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1;++i){
        int see;
        scanf(" %d",&see);
        g[see].push_back(i+1);
    }
    for(int i = 0; i < n;++i)
        scanf(" %d",&colors[i]);
    printf("%lld\n",solve(0,g).first);
    return 0;
}
