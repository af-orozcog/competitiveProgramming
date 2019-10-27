#include<iostream>
#include<cstring>
#define min(x,y)(x < y ? x:y)

using namespace std;

int dp[501][501];
int solution[501];
int vals[501];
int N,K;

int solve(int n,int p){
	if(n == N)
		return 0;
	if(dp[n][p] != -1)
		return dp[n][p];
	int ans = 1000000000;
	int from = K - p - vals[n];
	cout << from << endl;
	for(int i = from,co = from - vals[n]; i <=K;++i,++co){
		//cout << co << endl;
		int check = solve(n+1,i) + co;
		cout << " check es " << check<<endl;
		if(check < ans){
			ans = check;
			solution[n] = co;
		}
	}
	return dp[n][p] = ans;
}

int main(){
	scanf(" %d %d",&N,&K);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < N;++i) scanf(" %d",&vals[i]);
	printf("%d\n",solve(0,K));
	for(int i = 0; i < N;++i)
		printf("%d ",vals[i] + solution[i]);
	puts("");
	return 0;
}