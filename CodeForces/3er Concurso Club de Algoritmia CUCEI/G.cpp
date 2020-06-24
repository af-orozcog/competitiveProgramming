#include<bits/stdc++.h>
using namespace std;

int dp[(2*100000)+7];
int main(){
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    sort(nums,nums+n);
    for(int i = n-1; i > -1;--i){
        int next = lower_bound(nums,nums+n,nums[i]+m)-nums;
        if(next == n || nums[next] > nums[i]+m)
            --next;

        int many = next-i+1;
        if(many >= k){
            if(many > k)
                dp[i] = 1 + dp[i+k];
            else
                dp[i] = 1 + dp[next+1];
        }
        else
            dp[i] = dp[i+1];
    }
    printf("%d\n",dp[0]);
    return 0;
}
