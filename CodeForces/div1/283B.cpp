#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[2][200005];
int visited[2][200005];
ll ar[200005];
bool dp2[2][200005];

int loop = 1;
ll N;
bool flag = 0;
bool imp = 0;
bool how;

ll dfs(ll from, int pa){
    if(from > N || from < 1) return 0;
    if(from == 1){
        flag = 1;
        how = pa;
        return 0;
    }
    if(visited[pa][from] != 0){
        if(dp[pa][from] == 0) imp = 1;
        else if(dp[pa][from] < 0) flag = 1;
        return dp[pa][from];
    }
    if(visited[pa][from] == loop){
        imp = 1; return 0;
    }
    visited[pa][from] = loop;
    ll sum = dfs(from + (pa ? -ar[from]:ar[from]),(pa+1)&1);
    if(imp) dp[pa][from] = 0;
    else if(flag) dp[pa][from] = sum - ar[from], dp2[pa][from] = how;
    else dp[pa][from] = sum + ar[from];
    return dp[pa][from];
}

int main(){
    scanf(" %I64d",&N);
    for(int i = 2; i <= N;++i) scanf(" %I64d",&ar[i]);
    for(int i = 2; i <= N;++i){
        flag = imp = 0;
        if(visited[0][i] == 0){dfs(i,0);++loop;}
        flag = imp = 0;
        if(visited[1][i] == 0){dfs(i,1);++loop;}
    }
    for(int i = 1; i < N;++i){
        ll ans = i;
        if(dp[1][i+1] > 0) printf("%I64d\n",ans+dp[1][i+1]);
        else if(dp[1][i+1] == 0) puts("-1");
        else{
            bool check = dp2[1][i+1];
            if(!check) {puts("-1");}
            else printf("%I64d\n",-dp[1][i+1] + ans + (ll)i);
        }
    }
    return 0;
}
