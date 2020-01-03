#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
    int dp[2][3]; int memo[2][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    memo[1][0] = nums[0]-1;
    memo[1][1] = nums[0];
    memo[1][2] = nums[0] +1;
    memo[0][0] = memo[0][1] = memo[0][2] = -1000;
    for(int i = 1; i < n;++i){
        dp[1][0] = dp[1][1] = dp[1][2] = 0;
        int index;
        for(int j = 0; j < 3;++j){
            if(memo[0][j] == nums[i] || memo[1][j] == nums[i]){
                if(dp[0][j] + 1 > ans)
                    dp[1][0] = dp[0][j] + 1
            }
        }
    }
}
