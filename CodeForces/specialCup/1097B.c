/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max(x,y)(x > y? x:y)

int memo[16][360];
int N;
int nums[16];

int solve(int toTake,int sum){
	if(toTake == N){
		if(sum == 0)
			return 1;
		else
			return INT_MIN;
	}
	if(memo[toTake][sum]!= 0)
		return memo[toTake][sum];
	int neSum1 = sum +nums[toTake];
	int neSum2 = sum - nums[toTake];
	if(neSum1 >= 360)
		neSum1 -= 360;
	if(neSum2 < 0)
		neSum2 += 360;
	return memo[toTake][sum] = max(solve(toTake+1,neSum1),solve(toTake+1,neSum2));
}

int main(){
	//puts("lil");
	scanf(" %d",&N);
	memset(memo,0,sizeof(memo));
	for(int i = 0; i < N;++i){
		scanf(" %d",&nums[i]);
	}
	int ans = solve(0,0);
	if(ans < 0)
		puts("NO");
	else
		puts("YES");
	return 0;
}