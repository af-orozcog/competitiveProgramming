#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll calc(ll mi, ll seen, ll sum, ll n){
    return (mi*(n-seen+1)) + sum - mi;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll ans = LLONG_MAX;
        int n;
        scanf(" %d",&n);
        ll nums[n];
        ll mi[n];
        ll sum[n];
        for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
        for(int i = 0; i < n;++i){
            sum[i] = mi[i] = nums[i];
            if(i > 1)
                sum[i] += sum[i-2], mi[i] = min(mi[i-2],mi[i]);
        }
        for(int i = 2; i <= n;++i){
            if(i %2 == 0)
                ans = min(ans,calc(mi[i-1],i/2,sum[i-1],n) + calc(mi[i-2],i/2,sum[i-2],n));
            else
                ans = min(ans,calc(mi[i-1],i/2+1,sum[i-1],n) + calc(mi[i-2],i/2,sum[i-2],n));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
