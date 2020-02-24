#include<bits/stdc++.h>
#define ll long long
using namespace std;
class DFSCount{
    ll dp[14][(1<<14)];
    ll dp2[14][(1<<14)];
    int co;
     public:
        pair<ll,ll> dfs(int p, int ma,vector<vector<int>> graph){
            if(dp[p][ma] != -1) return {dp[p][ma],dp2[p][ma]};
            ll ans = 0;
            int neMa = ma;
            int en = 0;
            for(int i = 0; i < graph[p].size();++i){
                int va = (1<<graph[p][i]);
                if(va & ma) continue;
                pair<ll,ll> see1,see2;
                see1 = dfs(graph[p][i],ma|va,graph);
                see2 = dfs(p,see1.second,graph);
                ans += see1.first*see2.first;
                neMa = neMa | see1.second | see2.second;
                en = 1;
            }
            if(!en) return {dp[p][ma] = 1, dp2[p][ma] = neMa};
            return {dp[p][ma] = ans,dp2[p][ma] = neMa};
        }

        ll count(vector<string> G)
        {
            memset(dp,-1,sizeof(dp));
            int siz = G.size();
            co = (1<<siz)-1;
            vector<vector<int>> graph(siz);
            for(int i = 0; i < siz;++i){
                for(int j = 0; j < siz;++j)
                    if(G[i][j] == 'Y') graph[i].push_back(j);
            }
            ll ans = 0;
            for(int i = 0; i < siz;++i){
                int va = (1<<i);
                ans += dfs(i,va,graph).first;
            }
            return ans;
        }
};

int main(){
    DFSCount co;
    vector<string> G;
    G.push_back("NYY");
    G.push_back("YNN");
    G.push_back("YNN");
    cout << co.count(G)<< endl;
}

