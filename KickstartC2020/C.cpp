#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    set<int> per;
    for(int i = 0; i*i <= 10000000;++i)
        per.insert(i*i);
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        int sumMa = 0;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            sumMa = max(sumMa,sumMa+nums[i]);
        }
        int ans = 0;
        for(auto va:per){
            if(va > sumMa)break;
            map<int,int> dp;
            int sum = 0;
            for(int i = 0; i < n;++i){
                sum += nums[i];
                int look = sum - va;
                if(dp.count(look))
                    ans += dp[look];
                if(look == 0)
                    ans += 1;
                ++dp[sum];
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
