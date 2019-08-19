#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int dp[100][1400];
int ans[100][1400];

int v1,v2;
int T,D;
bool solve(int t, int s){
	if(t == T){
		if(s == v2)
			return true;
		else
			return false;
	}
	if(dp[t][s] != -1)
		return dp[t][s];
	for(int i = s +D; i >= max(1,s-D);--i){
		if(solve(t+1,i)){
			ans[t][s] = i;
			return dp[t][s] = true;
		}
	}
	return dp[t][s] = 0;
}

int main(){
	memset(dp,-1,sizeof(dp));
	memset(ans,-1,sizeof(ans));
	scanf(" %d %d",&v1,&v2);
	scanf(" %d %d",&T,&D);
	solve(1,v1);
	int w = v1;
	int f = v1;
	int i= 1;
	while(i < T){
		f = ans[i][f];
	//	cout << f << endl;
		w += f;
		++i;
	}
	printf("%d\n",w);
	return 0;
}