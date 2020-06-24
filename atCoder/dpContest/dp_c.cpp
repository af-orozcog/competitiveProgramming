#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][3];

int main(){
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < 3;++i) scanf(" %d",&dp[0][i]);
    for(int i = 1; i < n;++i){
        for(int j = 0; j < 3;++j){
            ll va; scanf(" %lld",&va);
            int bef = j - 1, af = j + 1;
            if(bef < 0) bef += 3;
            if(af == 3) af = 0;
            dp[1][j] = max(dp[0][bef],dp[0][af]);
            dp[1][j] += va;
        }
        memcpy(dp[0],dp[1],sizeof(dp[0]));
        memset(dp[1],0,sizeof(dp[1]));
    }
    printf("%lld\n",max(dp[0][0],max(dp[0][1],dp[0][2])));
    return 0;
}
