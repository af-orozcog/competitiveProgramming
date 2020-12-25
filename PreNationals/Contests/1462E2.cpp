#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll binExp(ll x, ll n, ll p){
    ll ans = 1;
    while(n){
        if(n&1) ans = (ans*x)%p;
        n >>= 1;
        x*= x;
        if(x >= p)
            x %= p;
    }
    return ans;
}

ll modInverse(ll x, ll p){
    return binExp(x,p-2,p);
}

ll factorials[1000000];

int main(){
    factorials[0] = 1;
    for(ll i = 1; i < 1000000;++i){
        factorials[i] = factorials[i-1]*i;
        if(factorials[i] >= MOD)
            factorials[i] %= MOD;
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m,k;
        scanf(" %d %d %d",&n,&m,&k);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        int j = 0;
        ll ans = 0;
        for(int i = 0; i < n;++i){
            while(j < n && nums[j]-nums[i] <= k)
                ++j;
            if(j == n || nums[j]-nums[i] > k)
                --j;
            if((j-i+1) < m ){
                ++j;
                continue;
            }
            ll nume = (j-i);
            ll imp = factorials[nume];
            ll divi = modInverse((factorials[m-1]*factorials[nume-m+1])%MOD,MOD);
            imp *= divi;
            if(imp >= MOD)
                imp %= MOD;
            ans += imp;
            if(ans >= MOD)
                ans -= MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
