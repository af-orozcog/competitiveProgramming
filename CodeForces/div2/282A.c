#include<stdio.h>

int main(){
	int n;
	scanf(" %d",&n);
	int i = 0;
	while(n--){
		int d = 0;
		for(int j = 0; j < 3;++j){
			char c;
			scanf(" %c",&c);
			if(d == 0){
				if(c == '+'){
					++i;
					d = 1;
				}
				if(c == '-'){
					--i;
					d = 1;
				}
			}
		}
	}
	printf("%d\n",i);
}