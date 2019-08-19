#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int s;
	scanf(" %d",&s);
	char ac[s+1];
	scanf(" %s",ac);
	int R = 0;
	int L = 0;
	int D = 0;
	int U = 0;
	for(int i = 0; i < s;++i){
		char a = ac[i];
		if(a == 'R')
			++R;
		if(a == 'U')
			++U;
		if(a == 'D')
			++D;
		if(a == 'L')
			++L;
	}
	printf("%d\n",min(R,L)+min(U,D));
	return 0;
}