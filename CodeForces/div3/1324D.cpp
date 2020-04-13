#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

int main(){
    int n;
    scanf(" %d",&n);
    int reve[n];
    pi nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i].first);
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i].second);
    for(int i = 0; i < n;++i){
        int val = nums[i].first - nums[i].second;
        reve[i] = val;
    }
    sort(reve,reve+n);
    ll ans = 0;
    for(int i = 0; i < n;++i){
        int see = nums[i].second - nums[i].first +1;
        int index = lower_bound(reve,reve+n,see) - reve;
        ans += (ll)n - (ll)index;
        if(see-1 < 0) --ans;
    }
    printf("%lld\n",ans>>1);
    return 0;
}
