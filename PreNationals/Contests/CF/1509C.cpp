#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll dp[2001][2001];
ll nums[3000];

ll go(int i, int j){
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = nums[j]-nums[i] + min(go(i+1,j),go(i,j-1));
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf(" %d",&n);
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    sort(nums,nums+n);
    printf("%lld\n",go(0,n-1));
    return 0;
}
