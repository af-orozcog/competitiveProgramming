#include<iostream>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

int dp[10001];
int nu[10001];
int nums[2];
int T;

int solve(int t){
	if(t == T)
		return T;
	if(t > T)
		return -1000000000;
	if(dp[t] != -1)
		return dp[t];
	int val1 = t;
	int val2 = solve(t + nums[0]);
	if(val2 > val1){
		nu[t] = t + nums[0];
		val1 = val2;
	}
	int val3 = solve(t + nums[1]);
	if(val3 > val1){
		nu[t] = t + nums[1];
		val1 = val3;
	}
	return dp[t] = val1;
}

int main(){
	int m,n;
	while(cin >> m >> n >> T){
		memset(dp,-1,sizeof(dp));
		memset(nu,-1,sizeof(nu));
		if(m < n){
			nums[0] = m;
			nums[1] = n;
		}
		else if(m > n){
			nums[0] = n;
			nums[1] = m;
		}
		else{
			nums[0] = m;
			nums[1] = n;
		}
		int le = solve(0);
		int co = 0;
		int ans = 0;
		while(nu[co] != -1){
			++ans;
			co = nu[co];
		}
		printf("%d",ans);
		if((T-le) != 0)
			printf(" %d",T-le);
		puts("");
	}
	return 0;
}