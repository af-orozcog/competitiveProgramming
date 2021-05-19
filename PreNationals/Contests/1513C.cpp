#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MOD = 1000000007;
ll dp[10][300001];

ll go(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    int dist = 10-i;
    if(j < dist) return dp[i][j] = 1;
    ll ans = go(1,j-dist) + go(0,j-dist);
    if(ans >= MOD) ans -= MOD;
    return dp[i][j] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        ll ans = 0;
        while(n){
            int va = n%10;
            ans += go(va,m);
            if(ans >= MOD) ans -= MOD;
            n /= 10;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
