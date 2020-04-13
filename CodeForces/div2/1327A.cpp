#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll fast(ll n){
    return (n*(n+1ll))>>1ll;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,k;
        scanf(" %lld %lld",&n,&k);
        if(n < k){puts("NO");continue;}
        n -= k;
        if((n&1) || (fast(k-1)<<1) > n) puts("NO");
        else puts("YES");
    }
    return 0;
}
