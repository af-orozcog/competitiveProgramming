#include<stdio.h>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

int main(){
	int n;
	scanf("%d",&n);
	int ans1,ans2;
	for(int i = n-1; i > (n>>1); --i){
		if(gcd(i,n-i) == 1){
			ans1 = n-i;
			ans2 = i;
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}