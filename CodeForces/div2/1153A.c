#include<stdio.h>

int abs(int x){return (x < 0)?-x:x;}

int main(){
	int n,t;
	scanf(" %d %d",&n,&t);
	int nums[2][n];
	int best;
	int dife = 1000000000;
	for(int i = 0; i < n;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		if(a > t && abs(t-a) < dife){
			dife = abs(t-a);
			best = i;
		}
		else if(a <= t){
			int temp = t - a;
			int d = temp/b;
			if(temp % b)
				d++;
			int le = a + (b*d);
			if(abs(t-le) < dife){
				dife = abs(t-le);
				best = i;
			}
		}
	}
	printf("%d\n",best+1);
	return 0;
}