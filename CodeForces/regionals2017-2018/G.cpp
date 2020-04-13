#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1000000007;
int r[100006],l[100006];
int info[100006];
ll dp[2][2][100006];
int dfs(int a, int e, int p){
    if(dp[a][e][p] != -1) return dp[a][e][p];
    ll r1,r2,r3,r4,l1,l2,l3,l4;
    r1 = (r[p] == -1? 1:dfs(0,0,r[p]));
    r2 = (r[p] == -1? 1:dfs(1,1,r[p]));
    r3 = (r[p] == -1? 0:dfs(1,0,r[p]));
    r4 = (r[p] == -1? 0:dfs(0,1,r[p]));

    l1 = (l[p] == -1? 1:dfs(0,0,l[p]));
    l2 = (l[p] == -1? 1:dfs(1,1,l[p]));
    l3 = (l[p] == -1? 0:dfs(1,0,l[p]));
    l4 = (l[p] == -1? 0:dfs(0,1,l[p]));
    ll ans = 0;
    if(info[p] == -1){
        if(a == 1 && e == 0)
            ans = (l4*r4 + r4*l2 + r2*l4)%MOD;
        if(a == 0 && e == 0)
            ans = (r2*l2)%MOD;
        if(a == 1 && e == 1)
            ans = (l1*) %MOD;
        if(a == 0 && e == 1)
            ans = (l3*r3 + r3*l2 + l3*r2) %MOD;
    }
    else if(info[p] == 1){
        if(a == 0 && e == 1)
            ans = ((l3+l2)*(r3+r2)) %MOD;
        if(a == 1 && e == 1)
            ans = (((  ((r1+r2+r3+r4)%MOD)*((l1+l2+l3+l4)%MOD) - (l3+l2)*(r3+r2)%MOD    ) %MOD)+MOD)%MOD;
        //if(ans < 0) ans += M;
    }
    else{
        if(a == 0 && e == 0)
            ans = ((l3+l2)*(r3+r2)) %MOD;
        if(a == 1 && e == 0)
            ans = (((  ((r1+r2+r3+r4)%MOD)*((l1+l2+l3+l4)%MOD) - (l3+l2)*(r3+r2)%MOD    ) %MOD)+MOD)%MOD;
    }
    return dp[a][e][p] = ans;
}

int main(){
    int n;
    while(scanf(" %d",&n) == 1){
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        for(int i = 1; i <= n;++i){
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            if(a != 0) l[i] = a;
            else l[i] = -1;
            if(b != 0) r[i] = b;
            else r[i] = -1;
            info[i] = c;
        }
         memset(dp,-1,sizeof(dp));
        ll ans = (dfs(0,1,1) + dfs(1,0,1))%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
