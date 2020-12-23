#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1000000007;

ll binExp(ll x,ll n,ll p){
    ll ans = 1;

    while(n){
        if(n&1) ans = (ans*x)%p;
        n >>= 1;
        x *= x;
        if(x >= p) x %= p;
    }

    return ans;
}

ll modInverse(ll n, ll p){
    return binExp(n,p-2,p);
}


bool works(int num, int a, int b){
    string st = to_string(num);
    for(auto va: st)
        if(va-'0' != a && va-'0' != b) return false;
    return true;
}

ll factorials[1000001];

int main(){
    factorials[0] = 1;
    for(ll i = 1; i < 1000001;++i){
        factorials[i] = factorials[i-1]*i;
        if(factorials[i] >= MOD) factorials[i] %= MOD;
    }
    int a,b,n;
    scanf(" %d %d %d",&a,&b,&n);
    ll ans = binExp(2,n,MOD);
    int initial = a*n + a - b;
    for(int i = 0; i <= n;++i){
        initial += b;
        initial -= a;
        if(!works(initial,a,b)){
            ll imp = factorials[n];
            imp *= modInverse((factorials[n-i]*factorials[i])%MOD,MOD);
            if(imp >= MOD) imp %= MOD;
            ans -= imp;
            if(ans < 0) ans += MOD;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
