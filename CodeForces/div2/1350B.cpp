#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        int dp[n];
        int ans = 1;
        for(int i = 0; i < n;++i) {scanf(" %d",&nums[i]); dp[i] = 0;}
        for(int i = n; i > 0;--i){
            dp[i-1] = 1;
            for(int j = 2; j*i <= n;++j)
                if(nums[i-1] < nums[(j*i)-1]) dp[i-1] = max(dp[i-1],dp[(j*i)-1]+1);
            ans = max(dp[i-1],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
