#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    map<int,ll> fr;
    ll ans = 0;
    for(int i = n-1;i > -1;--i){
        int c = i+1;
        int look = c - nums[i];
        fr[look] += (ll)nums[i];
        ans = max(ans,fr[look]);
    }
    printf("%lld\n",ans);
    return 0;
}
