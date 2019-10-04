#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#define max(x,y)(x > y?x:y)

using namespace std;

int dp[1000001];
int nums[9];

int solve(int n){
	if(n < 0)
		return -1;
	if(dp[n] != -1)
		return dp[n];
	int ans = 0;
	for(int i = 0; i < 9;++i)
		ans = max(ans,solve(n-nums[i])+1);
	return dp[n] = ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < 9;++i) scanf(" %d",&nums[i]);
	int val = solve(n);
	if(val == 0){
	    puts("-1");
	    return 0;
	}
//	cout << "lol" << endl;
	string ans = "";
	int pos = n;
	while(val--){
		int next;
		int i = 8;
		for(; i >= 0;--i){
			if(pos - nums[i] >= 0 && dp[pos-nums[i]] == val){
				next = pos -nums[i];
				break;
			}
		}
		pos = next;
		ans += ((i+1)+'0');
	}
	cout << ans << endl;
	return 0;
}
