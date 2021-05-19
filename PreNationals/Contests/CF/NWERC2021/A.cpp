#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll gcd(ll a, ll b){
    return b == 0? a: gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}

pi maxx(pl &a,pl &b){
    if(a.first*b.second >= b.first*a.second) return a;
    return b;
}


int main(){
    int n,q;
    scanf(" %d %d",&n,&q);
    int nums[n+1];
    nums[0] = 0;
    for(int i = 1; i <= n;++i) scanf(" %d",&nums[i]);
    pl use = {1,nums[1]};
    ll imp = gcd(use.first,use.second);
    use.first /= imp, use.second /= imp;
    for(int i = 2; i <= n;++i){
        pl comp = {i,nums[i]};
        imp = gcd(comp.first,comp.second);
        comp.first /= imp, comp.second /= imp;
        use = maxx(use,comp);
    }
    int co = 2*10000+1;
    ll dp[2*10000+1];
    for(int i = 1; i <= n;++i) dp[i] = (ll)nums[i];
    for(int i = n+1; i < co;++i){
        dp[i] = LLONG_MAX;
        for(int j = 1;j <= n;++j)
            dp[i] = min(dp[i],dp[j]+dp[i-j]);
    }
    while(q--){
        int k;
        scanf(" %d",&k);
        if(k < co){
            printf("%lld\n",dp[k]); continue;
        }
        ll x = (k-co)/use.first + 1;
        ll ans = x*(ll)nums[use.first];
        k -= x*use.first;
        ans += dp[k];
        printf("%lld\n",ans);
    }
    return 0;
}
