#include<bits/stdc++.h>

using namespace std;

int dp[101][101];
const int mo = 1000000;

int mod(int i){
    if(i  >= mo) return i - mo;
    else return i;
}

int main(){
    dp[0][0] = 1;
    for(int i = 1; i < 101;++i){
        for(int j = 100;j > -1;--j){
            for(int k = 0; k + j < 101;++k) dp[i][k+j] += dp[i-1][j], dp[i][k+j] = mod(dp[i][k+j]);
        }
    }
    while(1){
        int n,k;
        scanf(" %d %d",&n,&k);
        if(n == k && k == 0) break;
        printf("%d\n",dp[k][n]);
    }
    return 0;
}
