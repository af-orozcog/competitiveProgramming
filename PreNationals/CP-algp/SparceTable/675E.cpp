#include<bits/stdc++.h>
#define ll long long
using namespace std;

int K = 25;
int lg2[1000000];

int main(){
    lg2[1] = 0;
    for(int i = 2; i < 1000000;++i)
        lg2[i] = 1 + lg2[i>>1];
    int n;
    scanf(" %d",&n);
    int nums[n];
    nums[n-1] = n-1;
    for(int i = 0; i < n-1;++i){
        scanf(" %d",&nums[i]);
        --nums[i];
    }
    int st[K+1][n];
    int who[K+1][n];
    ll dp[n];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i < n;++i)
        st[0][i] = nums[i],who[0][i] = i;
    for(int i = 1; i <=K;++i){
        for(int j = 0; j +(1<<i) <= n;++j){
            if(st[i-1][j] <= st[i-1][j+(1<<(i-1))])
                who[i][j] = who[i-1][j],st[i][j] = st[i-1][j];
            else
                who[i][j] = who[i-1][j+(1<<(i-1))],st[i][j] = st[i-1][j+(1<<(i-1))];
        }
    }
    ll ans = 0;
    dp[n-1] = 0;
    for(int i = n-2; i > -1;--i){
        int imp = lg2[nums[i]-i];
        int wh;
        int val;
        if(st[imp][i+1] <= st[imp][nums[i]-(1<<imp)+1])
            wh = who[imp][i+1],val = st[imp][i+1];
        else
            wh = who[imp][nums[i]-(1<<imp)+1],val = st[imp][nums[i]-(1<<imp)+1];
        dp[i] = dp[wh] - (nums[i]-wh) + n - i- 1;
        ans += dp[i];
    }
    printf("%lld\n",ans);
    return 0;
}
