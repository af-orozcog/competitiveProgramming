#include<stdio.h>

int main(){
	int siz;
	scanf(" %d",&siz);
	int ar[siz];
	int dp[siz];
	for(int i = 0; i < siz;++i)
		scanf(" %d",&ar[i]);
	dp[0] = ar[0];
	for(int i = 1;i < siz;++i)
		dp[i] = dp[i-1]^ar[i];
	int ans = 0;
	for(int i = 1;i <= (siz>>1);++i){
		//printf("i es: %d  %d\n ",i,(siz>>1));
		for(int j = 0; j <=(siz-(i*2));++j){
			int m = i-1;
			int a;
			int b;
			if(i == 1){
				if(ar[j] == ar[j+1])
					++ans;
				//printf("a: %d b: %d i: %d j is %d\n",a,b,i,j);
				continue;
			}
			if(j == 0){
				a = dp[j+m];
				b = dp[j+i+m] ^ dp[j+i-1];
			}
			else{
				a = dp[j+m] ^ dp[j-1];
				b = dp[j+i+m] ^ dp[j+i-1];
			}
		//	printf("a: %d b: %d i: %d j is %d\n",a,b,i,j);
			if(a == b)
				++ans;
		}
	}
	printf("%d\n",ans);
}