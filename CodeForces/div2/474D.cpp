#include<iostream>
#include<cstring>
#define ll long long
#define M 1000000007
     
using namespace std;
     
ll dp[100001];
     
int k;
     
ll solve(int s){
    if(s < 0){
    	return 0;
    }
    if(s == 0)
    	return 1;
    if(dp[s] != -1)
    	return dp[s];
    ll ans = solve(s-1);
    ans += solve(s-k);
    ans = ans % M;
    return dp[s] = ans;
}
     
int main(){
	int t;
	scanf(" %d %d",&t,&k);
	memset(dp,-1,sizeof(dp));
    solve(100000);
	while(t--){
		int a,b;
		scanf(" %d %d",&a,&b);
        ll ans = 0;
        for(int i = a; i <= b;++i){
            ans += dp[i];
            ans = ans % M;
        }
		cout << ans << endl;
	}
	return 0;
}