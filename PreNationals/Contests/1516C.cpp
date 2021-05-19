#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int MAX = 100*2000*2+4;
int dp[101][100*2000*2+4];

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    for(int i = 0; i <= n;++i){
        for(int j = 0; j < MAX;++j) dp[i][j] = 1000000;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n;++i){
        for(int j = 0; j + nums[i-1] < MAX;++j)
            dp[i][j+nums[i-1]] = min(dp[i][j+nums[i-1]],dp[i-1][j]);
        for(int j = MAX; j - nums[i-1] > -1;--j)
            dp[i][j-nums[i-1]] = min(dp[i][j-nums[i-1]],dp[i-1][j]);
        for(int j = 0; j < MAX;++j)
            dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
    }
    int where;
    int mi = INT_MAX;
    for(int i = 0; i < MAX;++i){
        if(i == 2000*100) continue;
        if(dp[n][i] < mi) mi = dp[n][i],where = i;
    }
    vector<int> ans;
    int pos = n;
    while(pos > 0){
        int fi = dp[pos-1][where],se = (where + nums[pos-1] < MAX? dp[pos-1][where + nums[pos-1]]:INT_MAX), thi = (where - nums[pos-1] > -1? dp[pos-1][where - nums[pos-1]]:INT_MAX);
        int see = min(fi,min(se,thi));
        if(see == fi)
            ans.push_back(pos);
        else if(see == se)
            where = where + nums[pos-1];
        else
            where = where - nums[pos-1];
        --pos;
    }
    printf("%d\n",(int)ans.size());
    for(auto va:ans) printf("%d ",va);
    puts("");
    return 0;
}
