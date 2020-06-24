#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    return b == 0? a : gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b,q;
        scanf(" %lld %lld %lld",&a,&b,&q);
        ll imp = lcm(a,b);
        while(q--){
            ll l,r;
            scanf(" %lld %lld",&l,&r);
            if(a == b || imp == max(a,b) || r < max(a,b)){
                printf("0 ");continue;
            }
            ll how = (r/imp) - ((l-1ll)/imp);
            --how;
            ll ans = (r-l+1ll);
            ll bef = ((l-1ll)/imp)*imp;
            ans -= max(0ll,max(a,b)-1ll+bef-l+1ll);
            ans -= max(0ll,how*(max(a,b)));
            if(imp <= r){
                ll p = (r-(r/imp)*imp);
                ll up = (r-(r/imp)*imp)+max(a,b)+1ll;
                if(up >= r)
                    ans -= r-p+1ll;
                else
                    ans -= max(a,b)-1;
            }
            printf("%lld ",max(ans,0ll));
        }
        puts("");
    }
    return 0;
}
