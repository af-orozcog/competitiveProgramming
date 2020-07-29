#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    vector<int> per;
    for(int i = 0; i*i <= 10000000;++i)
        per.push_back(i*i);
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        int maX = 0;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            maX = max(maX,nums[i]);
        }
        maX *= n;
        int ans = 0;
        map<int,int> dp;
        int sum = 0;
        for(int i = 0; i < n;++i){
            sum += nums[i];
            for(auto va:per){
                if(va > maX) break;
                ans += dp[sum-va];
                if(va == sum)
                    ++ans;
            }
            ++dp[sum];
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
