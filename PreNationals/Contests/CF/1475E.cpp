#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MOD = 1000000007;

ll binExp(ll n, ll x, ll p){
    ll ans = 1;
    while(x){
        if(x&1) ans = (ans*n)%p;
        n *= n;
        if(n >= p) n%=p;
        x >>=1;
    }
    return ans;
}

ll modInverse(ll n, ll p){
    return binExp(n,p-2,p);
}

ll fact[2000];

int main(){
    fact[0] = 1;
    for(int i = 1; i < 2000;++i){
        fact[i] = fact[i-1]*i;
        if(fact[i] >= MOD) fact[i] %= MOD;
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int nums[n];
        map<int,int> seen;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            ++seen[nums[i]];
        }
        sort(nums,nums+n);
        reverse(nums,nums+n);
        int last = -1, many = 0;
        for(int i = 0; i < k;++i){
            if(nums[i] != last)
                last = nums[i], many = 1;
            else ++many;
        }
        ll ans = fact[seen[last]];
        ans *= modInverse(fact[many],MOD);
        if(ans >= MOD) ans %= MOD;
        ans *= modInverse(fact[seen[last]-many],MOD);
        if(ans >= MOD) ans %= MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
