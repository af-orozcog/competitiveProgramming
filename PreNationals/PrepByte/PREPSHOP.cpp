#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

bool dp[1001][2001];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n;++i){
        for(int k = 0; k < 10;++k){
            int val;
            scanf(" %d",&val);
            if(val == -1) continue;
            for(int j = 0; j <= m;++j){
                if(val+j > m) break;
                dp[i][val+j] = dp[i][val+j] | dp[i-1][j];
            }
        }
    }
    if(dp[n][m])
        puts("Yes");
    else puts("No");
    return 0;
}
