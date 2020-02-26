#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1000000007;

vector<vector<int>> graph(500000);
int info[1000000];
ll dp[2][500000];
int visited[2][500000];

ll dfs(int w, int p){
    if(visited[w][p])
        return dp[w][p];
    if(graph[p].size() == 0)
        return 1;
    visited[w][p] = 1;
    ll ans = 0;
    if(w == 0){
        ll val1 = dfs(1,graph[p][0]);
        ll val2 = dfs(1,graph[p][1]);
        if(val1 > 0 && val2 > 0)
            ans += (dfs(1,graph[p][0])*dfs(1,graph[p][1]))%M;
    }
    else{
        set<pair<int,int>> over;
        ll val1 = dfs(0,graph[p][0]);
        ll val2 = dfs(0,graph[p][0]);
        if(val1 > 0 || val2 > 0){
            int a = (val1 < 0? 1:0), b = (val2 < 0?1:0);
            //if(!over.count({a,b}))
                ans += (abs(val1)*abs(val2))%M;
            //over.insert({a,b});
        }
        val2 = dfs(1,graph[p][1]);
        if(!(val1 <= 0 && val2 >= 0)){
            int a = (val1 < 0? 1:0), b = (val2 < 0? 0:1);
            //if(!over.count({a,b}))
                ans += (abs(val1)*abs(val2))%M;
            //over.insert({a,b});
        }
        val1 = dfs(1,graph[p][0]);
        val2 = dfs(0,graph[p][0]);
        if(!(val2 <= 0 && val1>= 0)){
            //int a = (val1 < 0? 0:1),b = (val2 < 0?1:0);
            //if(!over.count({a,b}))
                ans += (abs(val1)*abs(val2))%M;
            //over.insert({a,b});
        }
    }
    if(info[p] != -1 && info[p] != w)
        ans = -ans;
    return dp[w][p] = ans;
}

int main(){
    int n;
    scanf(" %d",&n);
    int tot = 0;
    for(int i = 0;i < n;++i){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        --a,--b;
        if(a != -1) graph[i].push_back(a);
        else {graph[i].push_back(n+tot);++tot;}
        if(b != -1) graph[i].push_back(b);
        else {graph[i].push_back(n+tot);++tot;}
        info[i] = c;
    }
    //ll va = dfs(0,0);
    //if(va <= 0) va = 0;
    ll va = dfs(1,0);
    cout << va << endl;
    //if(temp < 0) temp = 0;
//    va += temp;
    cout << va << "\n";
    ll wut = 1;
    for(int i = 0; i < tot;++i){
        wut <<= 1;
        wut = wut % M;
    }
    ll ans = wut - va;
    if(ans < 0) ans+= M;
    printf("%lld\n",ans);
    return 0;
}
