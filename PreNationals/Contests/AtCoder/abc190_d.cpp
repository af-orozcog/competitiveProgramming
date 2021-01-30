#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    ll n;
    scanf(" %lld",&n);
    int ans = 0;
    ll upTo = sqrt(n*2LL);
    for(ll i = 1; i <= upTo;++i){
        if((n*2LL) % i == 0){
            ll see = 2LL*n - (i*i) + i;
            if(see % (2LL*i) == 0) ++ans;
            ll ot = (n*2LL) / i;
            if(ot != i && (2LL*n) % ot == 0){
                see = 2LL*n - (ot*ot) + ot;
                if(see % (2LL*ot) == 0) ++ans;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
