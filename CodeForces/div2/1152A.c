#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int ch[2];
	ch[0] = ch[1] = 0;
	int ke[2];
	ke[0] = ke[1] = 0;
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		++ch[val%2]; 
	}
	for(int i = 0; i < m;++i){
		int val;
		scanf(" %d",&val);
		++ke[val%2];
	}
	printf("%d\n",min(ch[0],ke[1])+min(ch[1],ke[0]));
	return 0;
}