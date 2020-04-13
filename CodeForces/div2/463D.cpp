#include<bits/stdc++.h>
using namespace std;

int dp[1001];
int n,k;
bitset<1001> nums[5][1000];
int vals[5][1000];

int main(){
    scanf(" %d %d",&n,&k);
    for(int i = 0; i < k;++i){
        bitset<1001> used;
        for(int j = 0; j < n;++j) scanf(" %d",&vals[i][j]);
        for(int j = n-1;j > -1;--j){
            nums[i][vals[i][j]] |= used;
            used[vals[i][j]] = 1;
        }
    }
    int ans = 0;
    for(int i = n-1;i > -1;--i){
        for(int j = 0; j < k;++j){
            dp[vals[j][i]] = 1;
            int add = 0;
            for(int q = 1; q <= n;++q){
                int va = 1;
                for(int w = 0; w < k && va;++w)
                    va = va & nums[w][vals[j][i]][q];
                if(va) add = max(add,dp[q]);
            }
            dp[vals[j][i]] += add;
            ans = max(dp[vals[j][i]],ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
