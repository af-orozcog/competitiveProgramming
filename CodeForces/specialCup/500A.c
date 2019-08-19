#include<stdio.h>

int N;
int nu[300001];

int posi(int i, int t){
	//printf("%d\n",i);
	if(i == t)
		return 1;
	if(i == N || i > t)
		return 0;
	return posi(i+nu[i],t);
}

int main(){
	int t;
	scanf(" %d %d",&N,&t);
	for(int i = 1; i < N;++i){
		scanf(" %d",&nu[i]);
	}
	if(posi(1,t))
		puts("YES");
	else
		puts("NO");
	return 0;
}