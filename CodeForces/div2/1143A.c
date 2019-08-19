#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int n;
	scanf(" %d",&n);
	int ce,one;
	for(int i = 0; i < n;++i){
		int x;
		scanf(" %d",&x);
		if(x == 0)
			ce = i;
		else
			one = i;
	}
	printf("%d\n",min(one,ce)+1);
	return 0;
}