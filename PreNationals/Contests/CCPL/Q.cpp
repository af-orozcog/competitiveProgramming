#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll factorials[14];
ll dp[14][14];

ll calculate(int where,int possible,vector<int> &taken){
    ll ans = 0;
    int upTo = taken[where] + possible;
    if(where)
        upTo -= (taken[where-1]+1);
    if(where+1 == taken.size())
        return factorials[upTo];
    for(int i = 0; i <= upTo;++i){
        ans += factorials[i]*calculate(where+1,upTo-i,taken);
    }
    if(where == 0)
        taken.pop_back();
    return ans;
}

ll ways(int where, vector<int> &taken,int ma, int needed){
    if(needed == 0)
        return 1;
    if(where == ma+1)
        return 0;
    if(where == ma && taken.size()+1 == needed){
        taken.push_back(ma);
        return calculate(0,0,taken);
    }
    taken.push_back(where);
    ll ans = ways(where+1,taken,ma,needed);
    taken.pop_back();
    ans += ways(where+1,taken,ma,needed);
    return ans;
}

int main(){
    factorials[0] = 1;
    for(ll i = 1; i < 14;++i)
        factorials[i] = factorials[i-1]*i;
    vector<int> send;
    //ways(0,send,ma,3)
    memset(dp,1,sizeof(dp));
    for(int i = 0; i < 14;++i)
        for(int j = 0; j < 14;++j)
            dp[i][j] = 1;
    //    ways(0,send,1,1);
    for(int i = 1;i < 14;++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = ways(0, send, i - 1, j);
            send.clear();
        }
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,l,r;
        scanf(" %d %d %d",&n,&l,&r);
        if(l == 0 || r == 0){
            puts("0");
            continue;
        }
        ll ans = 0;
        for(int i = 1; i <= n;++i){
            if(i < l || (n-i+1) < r || l < ((i!= 1)+1) || r < ((i!=n)+1)) continue;
            ans += dp[i-1][l-1]*dp[n-i][r-1]*(factorials[n-1]/factorials[n-1-(i-1)]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
