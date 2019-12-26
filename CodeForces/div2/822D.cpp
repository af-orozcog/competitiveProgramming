#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1000000007;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll dp[5000001];

int main(){
    dp[0] = 0;
    dp[1] = 0;
    for(ll i = 2; i < 5000001;++i){
        ll ans = 0;
        if(i&1) ans += 3;
        ans += i>>1;
        dp[i] = ans + dp[i>>1];
        dp[i] = dp[i] % mod;
    }
    ll t,l,r;
    cin >> t >> l >> r;
    ll ans = 0;
    for(ll i = l, k = 0; i <= r;++i,++k){
        ans += power(t,k,mod);
        cout << dp[i] << endl;
        ans *= dp[i];
        ans = ans % mod;
    }
    cout << ans << endl;
}
