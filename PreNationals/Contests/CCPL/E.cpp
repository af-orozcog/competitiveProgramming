#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1))>>1;
}

int main(){
    ll N;
    while(scanf(" %lld",&N) == 1){
        ll ans = 1;
        --N;
        if(N != 0) ans += 2;
        if(N > 1){
            ll val = fastSum(N>>1);
            --val;
            val <<= 2;
            ll sum = ((N>>1)+1)<<1;
            ans += val;
            ans += sum;
            if(N&1)
                ans += sum;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
