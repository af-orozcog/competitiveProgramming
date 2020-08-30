#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    map<char,int> ind;
    ind['B'] = 2;
    ind['R'] = 0;
    ind['G'] = 1;
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int dp[3][3][n];
        dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = 0;
        dp[0][1][0] = dp[1][1][0] = dp[2][1][0] = 0;
        dp[0][2][0] = dp[1][2][0] = dp[2][2][0] = 0;
        for(int i = 0; i < n;++i){
            if(i){
                dp[0][0][i] = dp[0][0][i-1];
                dp[0][1][i] = dp[0][1][i-1];
                dp[0][2][i] = dp[0][2][i-1];
                dp[1][0][i] = dp[1][0][i-1];
                dp[1][1][i] = dp[1][1][i-1];
                dp[1][2][i] = dp[1][2][i-1];
                dp[2][0][i] = dp[2][0][i-1];
                dp[2][1][i] = dp[2][1][i-1];
                dp[2][2][i] = dp[2][2][i-1];
            }
            char va;
            scanf(" %c",&va);
            ++dp[ind[va]][i%3][i];
        }
        int ans = k;
        for(int i = 0; i <= n-k;++i){
            for(int j = 0; j < 3;++j){
                int one = dp[j][i%3][i+k-1];
                int two = dp[(j+1)%3][(i+1)%3][i+k-1];
                int three = dp[(j+2)%3][(i+2)%3][i+k-1];
                if(i){
                    one -= dp[j][i%3][i-1];
                    two -= dp[(j+1)%3][(i+1)%3][i-1];
                    three -= dp[(j+2)%3][(i+2)%3][i-1];
                }
                ans = min(ans,k-(one+two+three));
            }
        }
        printf("%d\n",ans);
    }
}
