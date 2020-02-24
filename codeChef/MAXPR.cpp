#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[101][201];
ll seen[101];
const ll M = 1000000007;


ll mod(ll x, ll y){
    ll va = x % y;
    if(va < 0) return va + y;
    return va;
}

ll power(ll x, ll y){
    ll res = 1;     // Initialize result
    x = x %M;
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)%M;
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x)%M;  // Change x to x^2
    }
    return res;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll ans = 0;
        ll total = 0;
        ll tot = 0;
        memset(dp,0,sizeof(dp));
        memset(seen,0,sizeof(seen));
        int n; scanf(" %d",&n);
        for(int k = 0; k < n;++k){
            int re; scanf(" %d",&re);
            ll added = 0;
            ll coun = 0;
            for(int i = 0, j = -100; i < 201;++i,++j){
                if(re + j > 0 && re + j < 101 && j!= 0){
                    added += dp[re+j][i] + seen[re+j];
                    dp[re][i] += dp[re+j][i] + seen[re+j];
                    added = (added % M);
                    dp[re][i] = (dp[re][i] % M);
                    coun += dp[re+j][i];
                    coun = coun % M;
                }
            }
            ans =  (ans << 1ll);
            ans = ans % M;
            ans += mod(tot - (power(2,seen[re]))+seen[re]+1ll,M);
            ans += mod(total - coun,M);
            ans = ans % M;
            total += added;
            total = total % M;
            tot = mod(tot-power(2,seen[re])+ seen[re]+1ll,M);
            ++seen[re];
            tot += power(2,seen[re]) - seen[re] - 1ll;
            tot = mod(tot,M);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
