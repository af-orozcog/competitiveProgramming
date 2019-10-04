#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int im[2] = {0,0};
	int n; scanf(" %d",&n);
	for(int i = 0;i < n;++i){
		int va;scanf(" %d",&va);
		++im[va%2];
	}
	printf("%d\n",min(im[0],im[1]));
	return 0;
}