#include<stdio.h>

int main(){
	int n;
	scanf(" %d",&n);
	if((n &1) == 0){
		puts("NO");
		return 0;
	}
	for(int i = 1; i <= n;++i){
		if(i == 1)
			printf("%d %d",i,((i+1)<<1));
		else if (i&1)
			printf(" %d %d",i,i<<1);
		else
			printf(" %d %d",(i<<1)+1,i);
	}
	puts("");
	return 0;
}