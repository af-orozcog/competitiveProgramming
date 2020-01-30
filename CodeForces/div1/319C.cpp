#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100001];
ll he[100001],co[100001];
int N;

ll solve(int i){
    if(i == N-1) return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i] = LLONG_MAX;
    ll sum = 0;
    for(int j = i+1; j < N;++j){
        dp[i] = min(dp[i],co[i]*he[j]+solve(j)+sum);
        sum += co[N-1]*he[j];
    }
    return dp[i];
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d",&N);
    for(int i = 0; i < N;++i)
        cin >> he[i];
    for(int i = 0; i < N;++i)
        cin >> co[i];
    cout << solve(0) << "\n";
    return 0;
}
