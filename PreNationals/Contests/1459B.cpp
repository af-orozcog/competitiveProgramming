#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    ll n;
    scanf(" %lld",&n);
    ll x = n >> 1, y = n >> 1;
    if(n&1)++x;
    ll ans = (x+1)*(y+1);
    if(n&1) ans <<=1;
    printf("%lld\n",ans);
    return 0;

}
