#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100005];

int main(){
    ll n,w;
    scanf(" %lld %lld",&n,&w);
    for(int i = 0; i < 100005;++i) dp[i] = 1000000000000ll;
    dp[0] = 0;
    while(n--){
        ll we; int va;
        scanf(" %lld %d",&we,&va);
        for(int i = 100004; i > -1;--i)
            if(i-va > -1) dp[i] = min(dp[i],dp[i-va]+we);
    }
    int ans = 0;
    for(int i = 100004; i > -1 && !ans;--i){
        if(dp[i] <= w) ans = i;
    }
    printf("%d\n",ans);
    return 0;
}
