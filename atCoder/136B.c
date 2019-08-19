#include<stdio.h>

int digits(int n){
	int an = 0;
	while(n){
		n = n / 10;
		++an;
	}
	return an;
}

int main(){
	int n;
	scanf(" %d",&n);
	int dp[3];
	dp[0] = 9;
	dp[1] = 999-100;
	++dp[1];
	dp[2] = 99999-10000;
	++dp[2];
	int d = digits(n);
	//printf("%d\n",d);
	int ans = 0;
	if(d & 1){
		int le = 1;
		for(int i = 0; i < d-1;++i){le*= 10;}
	//	printf("%d\n",le);
		ans += n - le;
		++ans;
	}
	//printf("here %d\n",ans);
	for(int i = 0; i <= (d/2)-1;++i)
		ans += dp[i];
	printf("%d\n",ans);
	return 0;
}