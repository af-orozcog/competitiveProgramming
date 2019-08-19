#include<iostream>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

int dp[101][50001];
int nums[101];
int siz;
int half;

int solve(int p,int s){
	if(s > half)
		return -1;
	if(p == siz)
		return s;
	if(dp[p][s] != -1)
		return dp[p][s];
	int ans = max(solve(p+1,s),solve(p+1,s+nums[p]));
	return dp[p][s] = ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	while(n--){
		memset(dp,-1,sizeof(dp));
		scanf(" %d",&siz);
		int sum = 0;
		for(int i = 0; i < siz;++i){
			scanf(" %d",&nums[i]);
			sum += nums[i];
		}
		half = sum >> 1;
		int val = solve(0,0);
		printf("%d\n",(sum-val)-val);
	}
	return 0;
}