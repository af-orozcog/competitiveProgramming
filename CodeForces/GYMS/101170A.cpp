#include<bits/stdc++.h>
using namespace std;

int dp[10][41][41][402];
string ar[41];
string arN[41];
int n,t;

int solve(int i,int l,int r, int k){
    if(l > r) return 0;
    if(k == -1)return 0;
    if(i > 9) return 1000000000;
    if(dp[i][l][r][k] != -1) return dp[i][l][r][k];
    int ans = 1000000000;
    ans = min(ans,solve(i+1,l+1,r,k)+(i != ar[l][k]-'0'));
    for(int ne = i+1;ne < 10;++ne){
        ans = min(ans,solve(ne,l+1,r,k)+(i != ar[l][k]-'0'));
    }
    int co = 0;
    for(int to = l; to <= r;++to){
        co +=(i != ar[to][k]-'0');
        int addMin = 1000000000;
        for(int j = 0; j <= 9;++j)
            addMin = min(addMin,solve(j,l,to,k-1));
        if(to == r)
            ans = min(ans,co + addMin);
        for(int j = i+1; j <= 9;++j)
            ans = min(ans,solve(j,to+1,r,k) + co + addMin);
    }
    return dp[i][l][r][k] = ans;
}

void getAns(int i,int l,int r, int k){
    if(k == -1)return;
    if(l > r) return;
    int next = 0;
    int dig = 0;
    int see = 1000000000;
    int special = i;
    for(int ne = i+1;ne < 10;++ne){
        if(dp[ne][l+1][r][k]+(i != ar[l][k]-'0') < see)
            see = dp[ne][l+1][r][k]+(i != ar[l][k]-'0'),dig = ne,next = l + 1;
    }
    int co = 0;
    for(int to = l; to <= r;++to){
        co += (i != ar[to][k]-'0');
        int addMin = (k != 0?1000000000:0);
        int with = 0;
        for(int j = 0; j <= 9 && k;++j)
            if(addMin > dp[j][l][to][k-1])
                with = j,addMin = dp[j][l][to][k-1];
        if(to == r)
            if(co+addMin < see)
                see = co+addMin,special = with,next = r+1;
        for(int j = i+1;to + 1 <= r && j <= 9;++j)
            if(dp[j][to+1][r][k]+co+addMin < see)
                see = dp[j][to+1][r][k]+co+addMin,special = with,dig = j,next = to+1;
    }
    for(int to = l; to < next;++to){
        arN[to][k] = '0'+i;
    }
    if(l +1 < next)
        getAns(special,l,next-1,k-1);
    getAns(dig,next,r,k);
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> t;
    for(int i = 0; i < n;++i){
        cin >> arN[i];
        reverse(arN[i].begin(),arN[i].end());
        ar[i] = arN[i];
    }
    for(int i = 0; i < t;++i) {
        for (int num = 9; num > -1; --num) {
            for (int l = 0; l < n; ++l) {
                for (int r = l; r < n; ++r) {
                    solve(num, l, r, i);
                }
            }
        }
    }
    int ans = 1000000000;
    int dig;
    for(int i = 0; i < 10;++i){
        if(dp[i][0][n-1][t-1] < ans)
            dig = i, ans = dp[i][0][n-1][t-1];
    }
    getAns(dig,0,n-1,t-1);
    for(int i = 0; i < n;++i){
        reverse(arN[i].begin(),arN[i].end());
        cout << arN[i] << "\n";
    }
    //printf("%d\n",ans);
    return 0;
}
