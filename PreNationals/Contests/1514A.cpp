#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;


int MAX = 100005;
ll MOD = 1000000007;


ll binExp(ll n, ll p, ll m){
    ll ans = 1;
    while(p){
        if(p&1) ans = (ans*n);
        if(ans >= m) ans %= m;
        n *= n;
        if(n >= m) n %= m;
        p >>= 1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        ll ans = binExp(n,k,MOD);
        printf("%lld\n",ans);
    }
    return 0;
}
