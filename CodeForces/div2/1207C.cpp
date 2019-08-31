#include<iostream>
#include<cstring>
#define ll long long
#define min(x,y)(x < y?x:y)
     
using namespace std;
     
ll dp[2][200001];
string re;
int N;
ll a,b;
     
ll solve(int l,int p){
    if(p == N-1){
        if(!l)
            return a + b;
        return (a<<1) + b;
    }
    if(dp[l][p] != -1)
        return dp[l][p];
    ll ans;
    if(l && re[p] == '0')
        ans = min((a<<1) + b + solve(0,p+1),a + (b<<1)+solve(l,p+1));
    else if(!l && re[p] == '1')
        ans = (a<<1)+b+(b<<1) + solve(1,p+1);
    else if(l && re[p] == '1')
        ans = a + (b<<1) + solve(1,p+1);
    else
        ans = min((a<<1)+b+(b<<1) + solve(1,p+1), a + b + solve(l,p+1));
    return dp[l][p] = ans;
}
     
int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin >> N >> a >> b>> re;
        ll ans = b + solve(0,0);
        cout << ans << endl;
    }
}