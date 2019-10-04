#include<iostream>
#include<cstring>
#include<vector>
#define max(x,y)(x > y? x:y)

using namespace std;

int dp[201][10001];

int solve(int p, int l, int r,vector<int> &weight){
	if(l < 0 || r < 0)
		return -1;
	if(p == weight.size())
		return 0;
	if(dp[p][l]!= -1)
		return dp[p][l];
	return dp[p][l] = max(solve(p+1,l-weight[p],r,weight),solve(p+1,l,r-weight[p],weight))+1;
}

int main(){
	int t;
	scanf(" %d",&t);
	bool first = 0;
	while(t--){
		memset(dp,-1,sizeof(dp));
		if(first)
			puts("");
		first = 1;
		int be;
		scanf(" %d",&be);
		be *=100;
		vector<int> siz;
		while(1){
			int val;
			scanf(" %d",&val);
			if(val == 0)
				break;
			siz.push_back(val);
		}
		int ans = solve(0,be,be,siz);
		printf("%d\n",ans);
		int f1 = be;
		int f2 = be;
		for(int i = 0; i < ans;++i){
			if(f1 - siz[i] < 0){
				puts("port");
				f2 -= siz[i];
			}
			else if(f2 - siz[i] < 0){
				puts("starboard");
				f1 -= siz[i];
			}
			else if(dp[i+1][f1-siz[i]] != -1 && dp[i+1][f1-siz[i]] > dp[i+1][f1]){
				f1 -= siz[i];
				puts("starboard");
			}
			else{
				puts("port");
				f2 -= siz[i];
			}
		}
	}
	return 0;
}