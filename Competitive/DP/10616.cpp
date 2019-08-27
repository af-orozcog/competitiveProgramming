#include<iostream>
#include<cstring>

using namespace std;

int dp[20][10][200];

int N,D,M;
int nums[200];

int mod(int x, int y){
    return (x % y) < 0? ((x%y)+y):(x%y);
}

int solve(int r,int m,int n){
    if(m == M){
        if(r == 0)
            return 1;
        return 0;
    }
    if(n == N)
        return 0;
    if(dp[r][m][n] != -1)
        return dp[r][m][n];
    int ans = solve(mod((r+nums[n]),D),m+1,n+1) + solve(r,m,n+1);
    return dp[r][m][n] = ans;
}

int main()
{
    int Q;
    int va = 1;
    while(scanf("%d %d",&N,&Q) == 2){
        if(N == 0 && Q == 0)
            break;
        printf("SET %d:\n",va++);
        for(int i = 0; i < N;++i)
            scanf(" %d",&nums[i]);
        for(int i = 0; i < Q;++i){
            memset(dp,-1,sizeof(dp));
            scanf(" %d %d",&D,&M);
            printf("QUERY %d: %d\n",i+1,solve(0,0,0));
        }
    }
    return 0;
}