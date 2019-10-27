#include<stdio.h>

int main(){
	int n;
	scanf(" %d",&n);
	int page[n];
	for(int i = 0,temp = 0; i < n;++i) scanf(" %d %d",&temp,&page[i]);
	int pa;scanf(" %d",&pa);
	int i = 0;
	while(i < n-1 && page[i] < pa){
		++i;
	}
	printf("%d\n", n-i);
	return 0;
}