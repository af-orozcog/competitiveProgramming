#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    ll x;
    scanf(" %lld",&x);
    ll ans = (x/500ll);
    x -= ans*500ll;
    ans *= 1000ll;
    ans += (x/5ll)*5ll;
    printf("%lld\n",ans);
    return 0;
}
