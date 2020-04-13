#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(1){
        scanf(" %d %d",&n,&m);
        if(n == m && m == 0)break;
        int matrix[n][m];
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j) scanf(" %d",&matrix[i][j]);
        }
        int sum[n][m];
        int dp1[n],dp2[n],dp3[n];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        memset(dp3,0,sizeof(dp3));
        for(int i = 0; i < n;++i){
            for(int j = m-1; j > -1;--j){
                if(j == m-1) sum[i][j] = matrix[i][j];
                else if(j == m-2) sum[i][j] = max(matrix[i][j],sum[i][j+1]);
                else sum[i][j] = max(sum[i][j+2] + matrix[i][j],sum[i][j+1]);
                dp3[i] = max(dp3[i],sum[i][j]);
            }
            //printf("%d\n",dp3[i]);
        }
        for(int i = 0; i < n;++i){
            dp2[i] = dp3[i];
            if(i == 1) dp2[i] = max(dp3[i],dp2[i-1]);
            else if(i > 1)
                dp2[i] = max(dp3[i] +dp2[i-2],dp2[i-1]);
        }
        for(int i = n-1; i > -1;--i){
            dp1[i] = dp3[i];
            if(i == n-2) dp1[i] = max(dp3[i],dp1[i+1]);
            else if(i < n-2)
                dp1[i] = max(dp3[i] +dp1[i+2],dp1[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < n;++i){
            int comp = dp3[i];
            if(i > 1) comp += dp2[i-2];
            if(i < n-2) comp += dp1[i+2];
            ans = max(ans,comp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
