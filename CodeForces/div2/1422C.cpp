#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll sums[100004], mul[100004];
const ll mod = 1000000007;

ll fastSum(ll n){
    if(n <= 0) return 0;
    return (n*(n+1ll))>>1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string re;
    cin >> re;
    sums[0] = mul[0] = 1;
    for(ll i = 1; i < 100004;++i){
        mul[i] = mul[i-1]*10ll;
        if(mul[i] >= mod) mul[i] %= mod;
        sums[i] += sums[i-1] + ((i+1ll)*mul[i])%mod;
        if(sums[i] >= mod) sums[i] -= mod;
    }
    ll ans = 0;
    ll acum = 0;
    for(int i = re.size()-1,j = 0; i > -1;--i,++j){
        ll add = re[i]-'0';
        if(j > 0)
            ans += add*sums[j-1];
        if(ans >= mod) ans %= mod;
        ll imp = fastSum(i);
        if(imp >= mod) imp%= mod;
        ans += ((imp*mul[j])%mod)*add;
        if(ans >= mod) ans %= mod;

    }
    printf("%lld\n",ans);
    return 0;
}
