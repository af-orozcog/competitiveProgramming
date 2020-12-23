#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1000000007;

ll binExp(ll x, ll n, ll p){
    ll ans = 1;

    while(n){
        if(n&1) ans = (ans*x)%p;
        n >>= 1;
        x*=x;
        if(x >= p) x%=p;
    }
    return ans;
}

ll modInverse(ll x, ll p){
    return binExp(x,p-2,p);
}

ll factorials[4000000];


int main(){
    int t;
    scanf(" %d",&t);
    factorials[0] = 1;
    for(ll i = 1; i < 4000000;++i){
        factorials[i] = factorials[i-1]*i;
        if(factorials[i] >= MOD) factorials[i] %= MOD;
    }
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        ll sum = 0;
        ll ans = 1;
        ll temp;
        for(int i = 0; i < n;++i){
            scanf(" %lld",&temp);
            ll imp = factorials[sum+temp-1];
            imp *= modInverse((factorials[temp-1]*factorials[sum])%MOD,MOD);
            if(imp >= MOD) imp %= MOD;
            ans *= imp;
            if(ans >= MOD) ans %= MOD;
            sum += temp;
        }
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
