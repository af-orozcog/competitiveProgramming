/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

using namespace std;

int main(){
	int cas;
	scanf("%d",&cas);
	int ie = 0;
	while(cas--){
		++ie;
		int siz;
		scanf(" %d",&siz);
		char toCheck[siz+1];
		scanf(" %s",toCheck);
		int total = 0;
		int i = 1;
		while(i < siz){
			if(toCheck[i] == '.'){
				if(toCheck[i-1] == '#')
					++i;
				else{
					++total;
					i += 3;
				}
			}
			else if(toCheck[i] == '#'){
				if(toCheck[i-1] == '.' && i + 1 < siz && toCheck[i+1] == '.'){
					++total;
					i += 3;
				}
				else if(toCheck[i-1] == '.'){
					++total;
					if(toCheck[i+1] == '#')
						i += 3;
					else
						i += 2;
				}
				else if(i + 1 < siz && toCheck[i+1] == '.'){
					i += 2;
				}
				else
					i += 3;
			}
			if(i >= siz && (i - siz +1 < 2)){
				//printf("i es: %d\n",i);
				if(toCheck[siz-1] != '#')
					++total;
			}
		}
		printf("Case %d: %d\n",ie,total);
	}
	return 0;
}