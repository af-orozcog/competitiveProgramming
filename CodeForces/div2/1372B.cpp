#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        ll ma = n-1;
        ll ans[2] = {1ll,n-1ll};
        for(ll i = 1; i*i <= n;++i){
            if(n % i == 0){
                ll see = n/i;
                if(see > 1ll){
                    if(see-1ll < ma){
                        ma = see-1;
                        ans[0] = i;
                        ans[1] = i*(see-1ll);
                    }
                }
                ll ot = n / see;
                if(ot > 1ll){
                    if(ot-1ll < ma){
                        ma = ot-1ll;
                        ans[0] = see;
                        ans[1] = see*(ot-1ll);
                    }
                }
            }
        }
        printf("%lld %lld\n",ans[0],ans[1]);
    }
}
