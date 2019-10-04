// ALL I DO IS WRONG
#include<stdio.h>

int main(){
	int n;
	scanf(" %d",&n);
	int two = 0;
	int three = 0;
	while(n){
		if(n == 3){
			++three;
			n -= 3;
		}
		else{
			++two;
			n -= 2;
		}
	}
	printf("%d\n",two+three);
	for(int i = 0; i < two;++i)printf("%d ",2);
	if(three)
		printf("%d",3);
	puts("");
	return 0;
}