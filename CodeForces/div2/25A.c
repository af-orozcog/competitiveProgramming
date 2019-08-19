#include<stdio.h>

int main(){
	int siz;
	scanf(" %d",&siz);
	int o = 0;
	int e = 0;
	int oc = 0;
	int ec = 0;
	for(int i = 0; i < siz;++i){
		int val;
		scanf(" %d",&val);
		if(val & 1){
			o = i+1;
			++oc;
		}
		else{
			e = i+1;
			++ec;
		}
	}
	if(oc == 1)
		printf("%d\n",o);
	else
		printf("%d\n",e);
	return 0;
}