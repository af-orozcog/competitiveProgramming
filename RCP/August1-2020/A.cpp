#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000004];
int main(){
    int n;
    scanf(" %d",&n);
    map<int,ll> cost;
    cost[1] = 2;
    cost[0] = 6;
    cost[2] = 5;
    cost[3] = 5;
    cost[4] = 4;
    cost[5] = 5;
    cost[6] = 6;
    cost[7] = 3;
    cost[8] = 7;
    cost[9] = 6;
    for(ll i = 1; i <= n;++i){
        dp[i] = -100000000000000ll;
        for(int j = 0; j <= 9ll;++j){
            if(i - cost[j] < 0) continue;
            dp[i] = max(dp[i-cost[j]]+(ll)j,dp[i]);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
