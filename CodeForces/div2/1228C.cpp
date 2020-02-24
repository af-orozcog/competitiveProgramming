#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 1000000007;
typedef pair<ll,ll> pi;

ll sqr(ll va){
    ll lo = 1, hi = 1000000000, ans;
    while(lo <= hi){
        ll mid = (hi+lo)>>1;
        if(mid*mid <= va){ans = mid;lo = mid +1ll;}
        else hi = mid -1ll;
    }
    return ans;
}

ll power(ll x,ll y)
{
    ll res = 1;

    x = x % M;

    while (y > 0)
    {

        if (y & 1)
            res = (res*x) % M;
        y = y>>1;
        x = (x*x) % M;
    }
    return res;
}

set<ll> fact(ll va){
    ll to = sqr(va);
    set<ll> ans;
    for(ll i = 2; i <= to && va!= 1;++i){
        while(va % i == 0){
            va /= i;
            ans.insert(i);
        }
    }
    if(va != 1ll) ans.insert(va);
    return ans;
}

int main(){
    ll x,n;
    scanf(" %lld %lld",&x,&n);
    set<ll> see = fact(x);
    ll ans = 1;
    for(auto va:see){
        ll co = n;
        ll ad = va;
        ll su = 0;
        while(co >= va){
            su += co/va;
            co /= va;
        }
        ans *= power(va,su);
        ans = ans % M;
    }
    printf("%lld\n",ans);
    return 0;
}
