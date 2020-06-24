#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[15][(1<<14)+2];
ll nums[(1<<14)+2];
ll ma = LLONG_MAX;
int r;

ll solve(int d,int w,int lo, int hi){
    if(d == r) return 0ll;
    if(dp[d][w] != -1) return dp[d][w];
    dp[d][w] = ma;
    int mid = (lo+hi)>>1;
    if(w > mid){
        for(int i = lo; i <= mid;++i){
            if(nums[w] >= nums[i])
                dp[d][w] = min(dp[d][w],solve(d+1,i,lo,mid) + solve(d+1,w,mid+1,hi));
            else
                dp[d][w] = min(dp[d][w],solve(d+1,i,lo,mid) + (nums[i]-nums[w])*(nums[i]-nums[w]) + solve(d+1,w,mid+1,hi));
        }
    }
    else{
        for(int i = mid+1; i <= hi;++i){
            if(nums[w] >= nums[i])
                dp[d][w] = min(dp[d][w],solve(d+1,i,mid+1,hi) + solve(d+1,w,lo,mid));
            else
                dp[d][w] = min(dp[d][w],solve(d+1,i,mid+1,hi) + (nums[i]-nums[w])*(nums[i]-nums[w])+solve(d+1,w,lo,mid));
        }
    }
    return dp[d][w];
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf(" %d",&r);
    for(int i = 1; i <= (1<<r);++i) scanf(" %lld",&nums[i]);
    printf("%lld\n",solve(0,1,1,(1<<r)));
    return 0;
}
