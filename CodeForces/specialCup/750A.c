#include<stdio.h>

int main(){
	int n,k;
	scanf(" %d %d",&n,&k);
	int lo = 0,hi = n,mid;
	int max = 0;
	int com = 60 << 2;
	while(lo <= hi){
		mid = (lo+hi)>>1;
		int m = (mid*(mid+1))>>1;
		m = m * 5;
		if(com - (m + k) >= 0){
			max = mid;
			lo = mid + 1;
		}
		if(com - (m + k) <= 0)
			hi = mid -1; 
	}
	printf("%d\n",max);
	return 0;
}