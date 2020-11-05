#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int sum = 0;
    int nums[n];
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        sum += nums[i];
    }
    int dp[(sum/2)+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n;++i){
        for(int j = sum/2; j > 0; --j){
            if(j - nums[i] > -1)
                dp[j] = dp[j] | dp[j-nums[i]];
        }
    }
    int firstSeem = -1;
    for(int i = sum/2; i > -1 && firstSeem == -1;--i)
        if(dp[i])
            firstSeem = i;
    printf("%d\n",sum-2*firstSeem);
    return 0;
}
