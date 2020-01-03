#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,tar;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
        scanf(" %d",&tar);
        bool dp[n][(32000<<1)+1];
        memset(dp,0,sizeof(dp));
        dp[0][nums[0]+32000] = 1;
        for(int i = 1; i < n;++i){
            for(int j = 0; j < (32000<<1)+1;++j){
                if(j - nums[i] > -1 && dp[i-1][j-nums[i]])dp[i][j] = 1;
                if(j + nums[i] < (32000<<1)+1 && dp[i-1][j+nums[i]])dp[i][j] = 1;
                if((j-32000)%nums[i] == 0 && dp[i-1][((j-32000)/nums[i])+32000])dp[i][j] = 1;
                if(((j-32000)*nums[i])+32000 < (32000<<1)+1 && ((j-32000)*nums[i])+32000 > -1 && dp[i-1][((j-32000)*nums[i])+32000])dp[i][j] = 1;
            }
        }
        //cout << dp[1][12+32000] <<dp[2][3+32000] <<endl;
        if(!dp[n-1][tar+32000]){puts("NO EXPRESSION");continue;}
        char ans[n-1];
        int last = tar+32000;
        for(int i = n-1; i > 0; --i){
            if(last - nums[i] > -1 && dp[i-1][last-nums[i]]) ans[i-1] = '+', last = last-nums[i];
            else if(last + nums[i] < (32000<<1)+1 && dp[i-1][last+nums[i]])ans[i-1] = '-',last = last+nums[i];
            else if((last-32000)%nums[i] == 0 && dp[i-1][(last-32000)/nums[i]+32000]) ans[i-1] = '*', last = (last-32000)/nums[i]+32000;
            else ans[i-1] = '/',last = ((last-32000)*nums[i])+32000;
          //  cout << last << endl;
        }
        printf("%d",nums[0]);
        for(int i = 1; i < n;++i){
            printf("%c",ans[i-1]);
            printf("%d",nums[i]);
        }
        printf("=%d\n",tar);
    }
    return 0;
}
