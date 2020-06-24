#include<bits/stdc++.h>
using namespace std;

bool dp[100001];

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    dp[0] = false;
    for(int i = 1; i <=k;++i){
        for(int j = 0; j < n;++j){
            if(i - nums[j] >= 0)
                dp[i] = dp[i] | !dp[i-nums[j]];
        }
    }
    if(dp[k])
        puts("First");
    else puts("Second");
    return 0;
}
