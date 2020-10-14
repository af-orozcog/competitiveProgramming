#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000007;
ll modPow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        if(n < 3)
            printf("%lld\n",n);
        else if(n%3ll == 1ll)
            printf("%lld\n",(4ll*modPow(3,(n-4ll)/3ll))%mod);
        else if(n%3ll == 2ll)
            printf("%lld\n",(2ll*modPow(3,(n-2ll)/3ll))%mod);
        else
            printf("%lld\n",modPow(3,n/3ll));
    }
    return 0;
}
