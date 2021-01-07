#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1000000007;

ll factorials[1000000];
ll dp[10000];

int main(){
    factorials[0] = 1;
    for(ll i = 1; i < 1000000;++i){
        factorials[i] = factorials[i-1]*i;
        if(factorials[i] >= MOD)
            factorials[i] %= MOD;
    }
    ll n,m;
    scanf(" %lld %lld",&n,&m);
    for(int i = 0; i < m;++i){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
    }
    ll ans = factorials[(n-2*m)];

    dp[m-1] = m;
    for(int i = 1; i < 2*m;++i){
        for(int j = 0; j <= m;++j){
            ll used = (i - j);
            dp[j] = dp[j]*used;
            if(dp[j] >= MOD)
                dp[j] -= MOD;
            dp[j] += dp[j+1];
            if(dp[j] >= MOD)
                dp[j] -= MOD;
        }
    }
    ans *= dp[0];
    if(ans >= MOD)
        ans %= MOD;
    printf("%lld\n",ans);
    return 0;
}
