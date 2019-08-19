/**
* where's the joy?
*/
#include<stdio.h>

int main(){
	int siz;
	scanf(" %d",&siz);
	char l[siz+1];
	scanf(" %s",l);
	int c = 0;
	for(int i = 1;i < siz;++i){
		if(l[i-1] == l[i]){
			int co;
			if(l[i] == 'R'){
				l[i] = 'B';
				co = 1;
			}
			else if(l[i] == 'B'){
				l[i] = 'G';
				co = 2;
			}
			else{
				l[i] = 'R';
				co = 3;
			}
			if(i != siz - 1 && l[i] == l[i+1]){
				if(co == 1)
					l[i] = 'G';
				else if(co == 2)
					l[i] = 'R';
				else
					l[i] = 'B';
			}
			++c;
		}
	}
	printf("%d\n%s\n",c,l);
	return 0;
}