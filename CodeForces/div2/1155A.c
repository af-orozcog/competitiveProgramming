#include<stdio.h>

int main(){
	int siz;
	scanf(" %d",&siz);
	char ar[siz+1];
	scanf(" %s",ar);
	int com = 0;
	int work;
	int sizz = 0;
	int en = 0;
	for(int i = siz-1; i >= 0;--i){
		if(ar[i] <= ar[com] && com == 0){
			work = i;
			++com;
		}
		else if(ar[i] < ar[com]){
			++sizz;
			++en;
			break;
		}
		else if(ar[i] == ar[com]){
			++sizz;
			++com;
		}
		else{
			com = 0;
			sizz = 0;
		}
	}
	if(en){
		puts("YES");
		printf("%d %d\n",work-siz+1,work+1);
	}
	else
		puts("NO");
	return 0;
}