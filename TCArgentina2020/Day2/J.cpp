#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    if(n <= 0ll) return 0;
    return (n*(n+1ll))>>1;
}

ll fastSumFrom(ll from, ll to){
    return fastSum(to)-fastSum(from-1ll);
}

int main(){
    ll n,k;
    scanf(" %lld %lld",&n,&k);
    ll lo = 0, hi = k-1ll, ans = -1;
    while(lo <= hi){
        ll mid = (lo+hi)>>1;
        ll see = fastSumFrom(k-mid+1ll,k) - mid;
        ++see;
        if(see >= n)
            hi = mid-1ll,ans = mid;
        else
            lo = mid + 1ll;
    }
    printf("%lld\n",ans);
    return 0;
}
