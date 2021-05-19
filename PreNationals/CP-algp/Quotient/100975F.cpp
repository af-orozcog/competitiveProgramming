#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> phi;

ll binPow(ll n, ll p, ll mod = -1){
    ll ans = 1;
    while(p){
        if(p&1){
            ans = ans * n;
            if(mod != -1 && ans >= mod) ans %= mod;
        }
        p >>= 1;
        n *= n;
        if(mod != -1 && n >= mod) n %= mod;
    }
    return ans;
}

void sett(){
    phi.resize(1000001,0);
    for(int i = 2; i < phi.size();++i) phi[i] = i-1;

    phi[1] = 1;

    for(int i = 2; i < phi.size();++i){
        if(phi[i] == i-1){
            for(int j = i*2; j < phi.size(); j+=i) phi[j] -= phi[j]/i;
        }
    }
}


int main(){
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    sett();
    ll n,k;
    scanf(" %lld %lld",&n,&k);
    if(k & 1){
        ll imp = binPow(2,n,phi[k]);
        ll ans = binPow(2,imp,k);
        ++ans;
        if(ans >= k) ans -= k;
        printf("%lld\n",ans);
    }
    else{
        ll see = ceil(log2((double)k));
        if(n >= see){
            ll imp = binPow(2,n,phi[k])+phi[k];
            ll ans = binPow(2,imp,k);
            ++ans;
            if(ans >= k) ans -= k;
            printf("%lld\n",ans);
        }
        else{
            ll imp = binPow(2,n);
            ll ans = binPow(2,imp,k);
            ++ans;
            if(ans >= k) ans -= k;
            printf("%lld\n",ans);
        }
    }
}
