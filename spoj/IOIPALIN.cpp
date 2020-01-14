#include<bits/stdc++.h>
using namespace std;

char st[5001];
int dp[5000][5000];
int n;

int solve(int i, int j){
    if(i > j || i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(st[i] != st[j]) dp[i][j] = min(solve(i+1,j)+1,solve(i,j-1)+1);
    else dp[i][j] = solve(i+1,j-1);
    return dp[i][j];
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d %s",&n,st);
    printf("%d\n",solve(0,n-1));
    return 0;
}
