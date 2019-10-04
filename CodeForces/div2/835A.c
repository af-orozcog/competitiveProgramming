//ALL I DO IS WRONG
#include<stdio.h>

int main(){
	int s,v1,v2,t1,t2;
	scanf(" %d %d %d %d %d", &s,&v1,&v2,&t1,&t2);
	int tot1= (t1<<1)+(v1*s);
	int tot2 = (t2<<1)+(v2*s);
	if(tot1 < tot2)
		puts("First");
	else if(tot2 < tot1)
		puts("Second");
	else
		puts("Friendship");
	return 0;
}