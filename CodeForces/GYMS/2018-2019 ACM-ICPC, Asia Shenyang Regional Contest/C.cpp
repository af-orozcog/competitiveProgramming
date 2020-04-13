#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(ll va,ll mod){
    ll ans = 1;
    for(ll i = 2; i <= va;++i){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ll n,k,q;
        scanf(" %lld %lld %lld",&n,&k,&q);
        if(k >= n-1ll){
             printf("Case #%d: %lld\n",cas++,fact(n,q));
             continue;
        }
        ll imp = fact(k,q);
        ll pa1 = ((n-k-1)*(n-k-1))+1;
        //cout << pa1 << "\n";
        ll pa2 = (n-k-1);
        //cout << pa2*imp << "\n";
        ll pa3 = (n-k)*k;
        //cout << pa3*imp << "\n";
        //cout << pa1*imp << "\n";
        ll ans = (((imp*pa1)%q)+((imp*pa2)%q)+((imp*pa3)%q))%q;
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
