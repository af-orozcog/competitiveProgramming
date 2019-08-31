#include<stdio.h>
#include<string.h>
#define min(x,y)(x < y?x:y)
#define ll long long

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int dp[n];
	char map[n];
	for(int i = 0; i < n;++i)dp[i] = 20000;
	dp[n-1] = 0;
	for(int i = 0; i <n;++i) scanf(" %c",&map[i]);
	for(int i = n-1;i >= 0;--i){
		if(map[i] == '0')
			continue;
		for(int j = i+1,d = 0; j < n && d < m;++j,++d)
			dp[i] = min(dp[i], dp[j]+1);
	}
	printf("%d\n",(dp[0] >= 20000? -1:dp[0]));
	return 0;
}