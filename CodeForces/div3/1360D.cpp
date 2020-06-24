#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sqr(ll n){
    ll lo = 0,hi = n;
    ll ans = 1;
    while(lo <= hi){
        ll mid = (hi+lo)>>1;
        if(mid*mid <= n){
            ans = mid;
            lo = mid + 1ll;
        }
        else hi = mid - 1ll;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,k;
        scanf(" %lld %lld",&n,&k);
        ll to = sqr(n);
        ll ans = n;
        for(ll i = 1; i <= to+10ll && i <= k;++i){
            if(n % i == 0){
                ll ot = n/i;
                if(ot <= k) ans = min(ans,i);
                ans = min(ans,ot);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
