/**
*I'm sorry I was an Idiot
*/
#include<stdio.h>

int possible(int m, int k){
	int ones = 0;
	while(m){
		if(m & 1)
			++ones;
		m = m >> 1;
	}
	if(ones <= k)
		return 1;
	return 0;
}

int main(){
	int n,m,k;
	scanf(" %d %d %d",&n,&m,&k);
	int pos[m+1];
	for(int i = 0; i < m+1;++i){
		scanf(" %d",&pos[i]);
	}
	int last = pos[m];
	int total = 0;
	for(int i = 0; i < m;++i){
		int toCheck = last ^ pos[i];
		if(possible(toCheck,k))
			++total;
	}
	printf("%d\n",total);
}