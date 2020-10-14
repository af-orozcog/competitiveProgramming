#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,x;
    scanf(" %lld %lld",&n,&x);
    ll ans = 0;
    for(ll i = 1; i*i <= x;++i){
        if(x % i == 0){
            ll ot = x/i;
            if(i <= n && ot <= n && i != ot)
                ans += (2ll);
            else if(i <= n && ot <= n)
                ++ans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
