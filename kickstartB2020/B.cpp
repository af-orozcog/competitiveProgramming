#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ll n,d;
        scanf(" %lld %lld",&n,&d);
        ll nums[n];
        for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
        ll ans = d;
        for(int i = (int)n-1; i > -1;--i){
            ll va = (ans/nums[i])*nums[i];
            ans = va;
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
