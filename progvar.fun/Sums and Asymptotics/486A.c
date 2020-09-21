#include<stdio.h>
#define ll long long

int main(){
    ll n;
    scanf(" %lld",&n);
    ll ans = n>>1;
    if(n&1){
        ++ans;
        ans *= -1ll;
    }
    printf("%lld\n",ans);
    return 0;
}
