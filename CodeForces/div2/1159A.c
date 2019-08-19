/**
* where's the joy?
*/
#include<stdio.h>

int main(){
	int siz;
	scanf(" %d",&siz);
	char signs[siz+1];
	scanf(" %s",signs);
	int m = 0;
	for(int i = 0; i < siz;++i){
		if(signs[i] == '-'){
			m = m > 0? (m-1): m;
		} 
		else
			++m;
	}
	printf("%d\n",m );
}