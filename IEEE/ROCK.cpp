#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char nums[n];
        int dp[n+1];
        dp[n] = 0;
        for(int i = 0; i < n;++i) scanf(" %c",&nums[i]);
        for(int i = n-1; i > -1;--i){
            dp[i] = dp[i+1];
            int sum = 0;
            for(int j = i; j < n;++j){
                if(nums[j] == '0') --sum;
                else ++sum;
                if(sum > 0)
                    dp[i] = max(dp[i],j-i+1+dp[j+1]);
            }
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}
