#include<bits/stdc++.h>
#define ll long long
using namespace std;

int INF = INT_MAX;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        char see[n+1];
        scanf(" %s",see);
        vector<int> seen;
        for(int i = 0; i < n;++i)
            if(see[i] == '*')
                seen.push_back(i);
        vector<int> dp(seen.size(),INF);
        dp[0] = 1;
        for(int i = 1; i < seen.size();++i){
            dp[i] = 1;
            int add = INT_MAX;
            for(int j = i-1; j > -1;--j){
                if(seen[i]-seen[j] <= k)
                    add = min(add,dp[j]);
                else break;
            }
            dp[i] += add;
        }
        printf("%d\n",dp.back());
    }
    return 0;
}
