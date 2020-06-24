#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100005];

int main(){
    int n,w;
    scanf(" %d %d",&n,&w);
    for(int i = 0; i <= w;++i)
        dp[i] = -10000000000000000ll;
    ll ans = 0;
    dp[0] = 0;
    while(n--){
        int we;ll va;
        scanf(" %d %lld",&we,&va);
        for(int i = w; i > -1;--i){
            if(i - we > -1)
                dp[i] = max(dp[i],dp[i-we]+va);
            ans = max(ans,dp[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
