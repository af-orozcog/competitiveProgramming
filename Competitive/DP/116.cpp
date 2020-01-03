#include<bits/stdc++.h>
//#define LOCAL

using namespace std;

int main(){
    #ifdef LOCAL
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n,m;
    while(scanf(" %d %d",&n,&m) == 2){
        int nums[n][m];
        int dp[n][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m;++j) scanf(" %d",&nums[i][j]);
        for(int i = 0; i < n;++i) dp[i][m-1] = nums[i][m-1];
        for(int j = m-2; j > -1;--j){
            for(int i = 0; i < n;++i)
                dp[i][j] = nums[i][j] + min(dp[i][j+1],min(dp[(i+1)%n][j+1],dp[(((i-1)%n)+n)%n][j+1]));
        }
        int who,ma = 1000000000;
        for(int i = 0; i < n;++i)
            if(dp[i][0] < ma) who = i,ma = dp[i][0];
        int ans[m];
        ans[0] = who;
        for(int j = 1;j < m;++j){
            int check[] = {ans[j-1],(ans[j-1]+1)%n,(((ans[j-1]-1)%n)+n)%n};
            sort(check,check+3);
            int ma = 1000000000;
            int who = 0;
            for(int i = 0; i < 3;++i)
                if(dp[check[i]][j] < ma) who = check[i],ma = dp[check[i]][j];
            ans[j] = who;
        }
        for(int i = 0; i < m;++i){
            if(i == 0)printf("%d",ans[i]+1);
            else printf(" %d",ans[i]+1);
        }
        puts("");
        printf("%d\n",ma);
    }
    return 0;
}
