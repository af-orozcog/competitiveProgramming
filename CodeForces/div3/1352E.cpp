#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int sum = 0;
        unordered_map<int,int> dp;
        dp[sum] = 0;
        int nums[n];
        unordered_map<int,int> dif;
        for(int i = 1; i <= n;++i){
            scanf(" %d",&nums[i-1]);
            sum += nums[i-1];
            dp[sum] = i;
            ++dif[nums[i-1]];
        }
        int ans = 0;
        for(auto va:dif){
            int look = va.first;
            int temp = 0;
            bool found = 0;
            for(int j = 0; j < n;++j){
                temp += nums[j];
                if(dp.count(temp-look) && dp[temp-look] != j){
                    found = 1;break;
                }
            }
            if(found)
                ans += va.second;
        }
        printf("%d\n",ans);
    }
    return 0;
}
