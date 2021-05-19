#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MOD = 1000000007;
int upTo = 2*100000+2;
ll per[2*100000+2];

int main(){
    per[0] = 1;
    for(ll i = 1; i < upTo;++i){
        per[i] = per[i-1]*i;
        if(per[i] >= MOD) per[i] %= MOD;
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int mi = INT_MAX;
        int co = 0;
        for(int i = 0; i < n;++i){
            if(nums[i] < mi) mi = nums[i], co = 1;
            else if(nums[i] == mi) ++co;
        }
        bool posi = 1;
        for(int i = 0; i < n && posi;++i){
            if((nums[i]&mi) != mi) posi = 0;
        }
        if(!posi){puts("0");continue;}
        ll ans = (ll)co*(ll)(co-1);
        if(ans >= MOD) ans %= MOD;
        ans *= per[n-2];
        if(ans >= MOD) ans %= MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
