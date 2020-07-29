#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    if(n<= 0) return 0ll;
    return (n*(n+1ll))>>1;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,r;
        scanf(" %lld %lld",&n,&r);
        ll imp = fastSum(min(n-1ll,r));
        //cout << imp << "\n";
        r -= (n-1ll);
        if(r>0ll) r = 1ll;
        else r = 0ll;
        imp += r;
        printf("%lld\n",imp);
    }
    return 0;
}
