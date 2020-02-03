#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100001];
ll he[100001],co[100001];
int N;

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d",&N);
    for(int i = 0; i < N;++i)
        cin >> he[i];
    for(int i = 0; i < N;++i)
        cin >> co[i];
    ll ans = co[0]*he[N-1];
    for(int i = N-2; i > 0;--i)
        ans = min(ans,co[0]*he[i] + co[i]*he[N-1]);
    cout << ans << "\n";
    return 0;
}
