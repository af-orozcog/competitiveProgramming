#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MOD = 1000000007;

ll binExp(ll n, ll x, ll p){
    ll ans = 1;
    while(x){
        if(x&1) ans = (ans*n)%p;
        x >>= 1;
        n *= n;
        if(n >= p) n %= p;
    }
    return ans;
}

int main(){
    int k;
    scanf(" %d",&k);
    ll dp[k+1][k+1];
    memset(dp,0,sizeof(dp));
    ll ans = 0;
    for(int i )
    if(ans >= MOD) ans %= MOD;
    printf("%lld\n",ans);
    return 0;
}
