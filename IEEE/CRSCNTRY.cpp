#include<bits/stdc++.h>
using namespace std;

int dp[2005][2005];
int a[2005],b[2005];

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int ans = 0;
        int i = 0;
        while(scanf(" %d",&a[i++]))
            if(a[i-1] == 0) break;
        --i;
        while(1){
            int j = 0;
            scanf(" %d",&b[j++]);
            if(b[0] == 0) break;
            while(scanf(" %d",&b[j++]))
                if(b[j-1] == 0)break;
            --j;
            for(int k = 1; k<= i;++k)
                for(int q = 1; q <= j;++q){
                    if(a[k-1] == b[q-1])
                        dp[k][q] = dp[k-1][q-1] +1;
                    else
                        dp[k][q] = max(dp[k][q-1],dp[k-1][q]);
                }
            ans = max(ans,dp[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
