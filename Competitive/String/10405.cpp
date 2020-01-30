#include<bits/stdc++.h>

using namespace std;

int main(){
    string re1,re2;
    while(getline(cin,re1)){
        getline(cin,re2);
        int dp[(int)re1.size()+1][(int)re2.size()+1];
        dp[0][0] = 0;
        for(int i = 0; i <= re1.size();++i) dp[i][0] = 0;
        for(int i = 0; i <= re2.size();++i) dp[0][i] = 0;
        for(int i = 1; i <= re1.size();++i){
            for(int j = 1; j <= re2.size();++j){
                if(re1[i-1] == re2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                //printf("%d %d %d\n",dp[i][j],i,j);
            }
        }
        printf("%d\n",dp[re1.size()][re2.size()]);
    }
    return 0;
}
