/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int n,a,x,b,y;
	scanf(" %d %d %d %d %d",&n,&a,&x,&b,&y);
	int time1 = x < a ? (n-a+x):(x-a);
	int time2 = y > b ? (b+n-y):(b-y);
	int min = time1 < time2 ? time1:time2;
	int i = 0;
	int pos = 0;
	while(i < min){
		++a;
		--b;
		if(a > n)
			a -= n;
		if(b < 1)
			b+= n;
		if(a == b){
			pos = 1;
			break;
		}
		++i;
	}
	if(pos)
		puts("YES");
	else
		puts("NO");
	return 0;
}