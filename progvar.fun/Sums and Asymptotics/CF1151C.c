#include<stdio.h>
#define ll long long

ll mod = 1000000007;
ll fastSum(ll n){
    if(n < 0) return 0;
    if(n >= mod)
        n %= mod;
    return ((n*(n+1ll))>>1)%mod;
}

int main(){
    ll l,r;
    scanf(" %lld %lld",&l,&r);
    ll vals[2] = {1,0};
    ll i = 1, turn = 1;
    if(l == 1)vals[0] = 0;
    else --l;
    while(l > 1ll){
        i <<= 1;
        vals[turn] += i;
        l -= i;
        if(l <= 0) {
            vals[turn] += l;
            --vals[turn];
        }
        turn = (turn+1)&1;
    }
    ll less = (fastSum(vals[0]-1ll)<<1)%mod+(vals[0]%mod) + (fastSum(vals[1])<<1)%mod;
    if(less >= mod) less %= mod;
    vals[0] = 1, vals[1] = 0;
    i = 1, turn = 1;
    --r;
    while(r > 0){
        i <<= 1;
        vals[turn] += i;
        r -= i;
        if(r < 0ll)
            vals[turn] += r;
        turn = (turn+1)&1;
    }
    ll ans = (fastSum(vals[0]-1ll)<<1)%mod + (vals[0]%mod) + (fastSum(vals[1])<<1)%mod;
    if(ans >= mod) ans %= mod;
    ans -= less;
    if(ans < 0) ans += mod;
    printf("%lld\n",ans);
    return 0;
}
