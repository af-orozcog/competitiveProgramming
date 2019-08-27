#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>

using namespace std;
int dp[100][10001];
int dpmin[100][20001];
int nums[100];
int N,TAR;

int solve(int n, int t){
    if(t >= TAR)
        return t;
    if(n >= N)
        return 1000000;
    if(dp[n][t] != -1)
        return dp[n][t];
    return dp[n][t] = min(solve(n+1,t),solve(n+1,t+nums[n]));
}

int solve2(int n,int t){
    if(t < 0)
        return 1000000;
    if(t == 0)
        return 0;
    if(n == N)
        return 1000000;
    if(dpmin[n][t] != -1)
        return dpmin[n][t];
    return dpmin[n][t] = min(solve2(n+1,t),solve2(n+1,t-nums[n])+1);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(dpmin,-1,sizeof(dpmin));
        scanf(" %d %d",&TAR,&N);
        for(int i = 0; i < N;++i)
            scanf(" %d",&nums[i]);
        int getTo = solve(0,0);
        int co = solve2(0,getTo);
        printf("%d %d\n",getTo,co);
    }
    return 0;
}