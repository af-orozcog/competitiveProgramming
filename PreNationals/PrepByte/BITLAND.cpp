#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll factorials[1000001];
ll mod = 1000000007;


ll binExp(ll x, ll n, ll p){
    ll ans = 1;
    while(n){
        if(n&1) ans = (ans*x)%p;
        x*= x;
        if(x >= p)
            x %= p;
        n >>= 1;
    }
    return ans;
}

ll inverseMod(ll n, ll p){
    return binExp(n,p-2,p);
}

ll NCr(ll x, ll y, ll p){
    ll ans = factorials[x];
    ans *= inverseMod(factorials[y],p);
    if(ans >= p)
        ans %= p;
    ans *= inverseMod(factorials[x-y],p);
    if(ans >= p)
        ans %= p;
    return ans;
}

int main(){
    factorials[0] = 1;
    for(int i = 1; i < 1000001;++i){
        factorials[i] = factorials[i-1]*(ll)i;
        if(factorials[i] >= mod)
            factorials[i] %= mod;
    }
    int n,m;
    scanf(" %d %d",&n,&m);
    ll ans = 0;
    for(int i = 0; i < m;++i){
        if(i-n < 0) continue;
        if(i-n == 0 && m > 1)
            ans += NCr(i,m-1,mod);
        else if(i-n > 0)
            ans += NCr(i,m,mod);
        if(ans >= mod)
            ans -= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
