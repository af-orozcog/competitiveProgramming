#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    unordered_map<int,ll> fr;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        ++fr[nums[i]];
    }
    ll ans = 0;
    for(auto va:fr)
        ans += fastSum(va.second-1ll);
    for(int i = 0; i < n;++i)
        printf("%lld\n",ans-fr[nums[i]]+1ll);
    return 0;
}
