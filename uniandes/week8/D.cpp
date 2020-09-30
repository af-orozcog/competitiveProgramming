#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<ll> see(32,0);
        vector<ll> sum(32,0);
        for(int i = 0; i < n;++i){
            int last;
            int j = 0;
            int va;
            scanf(" %d",&va);
            while(va){
                if(va&1) last = j;
                ++j;
                va >>=1;
            }
            ++see[last];
            ++sum[last];
        }
        ll ans = 0;
        for(int i = 1; i < 32;++i)
            sum[i] += sum[i-1];
        for(int i = 31; i > 0;--i)
            ans += see[i]*sum[i-1];
        printf("%lld\n",fastSum(n-1)-ans);
    }
    return 0;
}
