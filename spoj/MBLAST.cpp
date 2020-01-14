#include<bits/stdc++.h>
using namespace std;

int main(){
    string re1,re2;
    cin >> re1 >> re2;
    int k;
    scanf(" %d",&k);
    vector<vector<int>> dp(re1.size()+1,vector<int> (re2.size()+1));
    dp[0][0] = 0;
    for(int i = 1; i <= re1.size();++i) dp[i][0] = dp[i-1][0] + k;
    for(int i = 1; i <= re2.size();++i) dp[0][i] = dp[0][i-1] + k;
    for(int i = 1; i <= re1.size();++i){
        for(int j = 1;j <= re2.size();++j)
            dp[i][j] = min(min(dp[i-1][j-1] + abs((re1[i-1]-'a')-(re2[j-1]-'a')),dp[i][j-1]+k),dp[i-1][j]+k);
    }
    printf("%d\n",dp[re1.size()][re2.size()]);
    return 0;
}
