/**
* Why the fuck am I doing this shit
*/
#include<stdio.h>
#include<string.h>
#define min(x,y)(x < y? x:y)

int main(){
	int n;
	scanf(" %d",&n);
	short check[n];
	for(int i = 0;i < n;++i) scanf(" %hd",&check[i]);
	int dp[2][3];
	dp[0][0] = dp[0][1] = dp[0][2] = 1;
	if(check[n-1] == 1)
		dp[0][0] = 0;
	else if(check[n-1] == 2)
		dp[0][1] = 0;
	else if(check[n-1] == 3)
		dp[0][1] = dp[0][0] = 0;
	for(int i = n-2;i >= 0;--i){
		dp[1][2] = min(dp[0][0],min(dp[0][1],dp[0][2])) +1;
		if(check[i] == 1){
			dp[1][0] = min(dp[0][1],dp[0][2]);
			dp[1][1] = min(dp[0][0],dp[0][2]) + 1;			
		}
		if(check[i] == 2){
			dp[1][0] = min(dp[0][1],dp[0][2]) +1;
			//printf("%d\n",dp[1][0]);
			dp[1][1] = min(dp[0][0],dp[0][2]);
		}
		if(check[i] == 3){
			dp[1][0] = min(dp[0][1],dp[0][2]);
			dp[1][1] = min(dp[0][0],dp[0][2]);
		}
		if(check[i] == 0){
			dp[1][1] = min(dp[0][0],dp[0][2]) + 1;
			dp[1][0] = min(dp[0][1],dp[0][2]) +1;
		}
		//printf("%d %d %d\n",dp[1][0],dp[1][1],dp[1][2]);
		memcpy(dp[0],dp[1],sizeof(dp[1]));
	}
	printf("%d\n",min(dp[0][1],min(dp[0][0],dp[0][2])));
	return 0;
}