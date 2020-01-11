#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1<<20];
int nums[20][20];
int S;

ll solve(int mask, int bits){
    if(bits == S) return 1;
    if(dp[mask] != -1) return dp[mask];
    dp[mask] = 0;
    for(int i = 0; i < S;++i){
        if(nums[bits][i] == 1 && ((1<<i) & mask) == 0)
            dp[mask] += solve((1<<i)|mask,bits+1);
    }
    return dp[mask];
}

int main(){
    int t;scanf(" %d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf(" %d",&S);
        for(int i = 0; i < S;++i){
            for(int j = 0; j < S;++j) scanf(" %d",&nums[i][j]);
        }
        printf("%lld\n",solve(0,0));
    }
    return 0;
}
