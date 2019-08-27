#include<stdio.h>

int main(){
	int x,y,z;
	scanf(" %d %d %d",&x,&y,&z);
	int a,b,c;
	scanf(" %d %d %d",&a,&b,&c);
	if(a >= x)
		a-=x;
	else{
		puts("NO");
		return 0;
	}
	if(a+b < y){
		puts("NO");
		return 0;
	}
	if((a+b+c)-y < z){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}