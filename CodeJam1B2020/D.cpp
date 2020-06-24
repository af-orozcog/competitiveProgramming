#include<bits/stdc++.h>
using namespace std;
int dp[4002][4002];
vector<int> co[1000001];
int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    int ans2 = 1;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        co[nums[i]].push_back(i);
        ans2 = max(ans2,(int)co[nums[i]].size());
    }
    int ans = 0;
    for(int i = n-1;i > -1;--i){
        int ind = lower_bound(co[nums[i]].begin(),co[nums[i]].end(),i)-co[nums[i]].begin();
        ++ind;
        for(int j = i+1; j < n;++j){
            if(nums[i] == nums[j]){++ind;continue;}
            if(ind < (int)co[nums[i]].size())
                dp[i][j] = max(dp[i][j],dp[j][co[nums[i]][ind]]+1);
            else
                dp[i][j] = 1;
            ans = max(ans,dp[i][j]);
        }
    }
    printf("%d\n",max(ans+1,ans2));
    return 0;
}
