#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    ll n;
    scanf(" %lld",&n);
    ll ans = fastSum(n);
    ll nums[n];
    for(ll i = 0; i < n;++i)
        scanf(" %lld",&nums[i]);
    map<ll,int> fr;
    ll sum = 0;
    int last = -1;
    bool one = 0;
    for(ll i = 0; i < n;++i){
        sum += nums[i];
        if(fr.count(sum) && fr[sum]+1 > last){
            ll ri = (ll)n-i;
            ll le = ((fr[sum]+1)-last);
            ans -= le*ri;
            last = fr[sum]+1;
            one = 1;
        }
        else if(sum == 0 && !one){
            ll ri = n-i;
            ll le = 1;
            ans -= le*ri;
            last = 0;
            one = 1;
        }
        fr[sum] = i;
    }
    printf("%lld\n",ans);
    return 0;
}
