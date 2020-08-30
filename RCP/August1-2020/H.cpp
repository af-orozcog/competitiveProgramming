#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[102][102];
int nums[102];
int n;
int top;

int solve(int i, int k, int last){
    if(i == n) return 0;
    if(dp[i][k] != -1) return dp[i][k];
    int ans = 0;
    if(nums[i] > last){
        if(k >= top-1)
            ans = max(ans,solve(i+1,0,nums[i])+k+1);
        ans = max(ans,solve(i+1,k+1,nums[i]));
    }
    ans = max(ans,solve(i+1,k,last));
    ans = max(ans,solve(i+1,1,nums[i]));
    return dp[i][k] = ans;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %d",&n);
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        printf("%d",n);
        for(int i = 2; i <= n;++i){
            memset(dp,-1,sizeof(dp));
            top = i;
            printf(" %d",solve(0,0,-100000000));
        }
        puts("");
    }
    return 0;
}
