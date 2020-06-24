#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[10001];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    char ma[n][m];
    for(int i = 0; i < n;++i)
        for(int j = 0; j < m;++j) scanf(" %c",&ma[i][j]);
    dp[m-1] = 1;
    for(int i = m-2; i > -1;--i)
        if(ma[n-1][i] != '#') dp[i] = dp[i+1];
    for(int i = n-2;i > -1;--i){
        for(int j = m-1;j > -1;--j){
            if(ma[i][j] == '#'){
                dp[j] = 0;
                continue;
            }
            if(j != m-1) dp[j] += dp[j+1];
            if(dp[j] >= 1000000007) dp[j] -= 1000000007;
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}
