#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    if(n < 1ll) return 0ll;
    return (n*(n+1ll))>>1;
}


int main(){
    ll n,m,k;
    scanf(" %lld %lld %lld",&n,&m,&k);
    if(m >= n){
        printf("%lld\n",fastSum(n));
        return 0;
    }
    if(m == 1){
        ll times = n/k;
        printf("%lld\n",n*(times+1ll)-fastSum(times)*k);
        return 0;
    }
    ll weirdG = 1+((n - m)/k)*k;
    ll distribute = (n - m+1ll-weirdG);
    ll base = 1ll + (distribute)/(m);
    weirdG += base -1ll;
    ll weird = (distribute)%(m);
    ll ans = n;
    ll times;
    if(weird) ++weirdG,--weird;
    if(k > weirdG)
        times = 0;
    else times = weirdG/k;
    ans += n*times - fastSum(times)*k;
    n -= weirdG;
    ans += n*(weird+(weirdG%k != 0)) - fastSum(weird)*(base+1ll);
    n -= weird*(base+1ll);
    ans += n*(m-1-weird) - fastSum(m-1ll-weird)*base;
    printf("%lld\n",ans);
    return 0;
}
