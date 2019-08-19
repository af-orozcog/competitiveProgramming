#include<stdio.h>

int main(){
	int n,t;
	scanf(" %d %d",&n,&t);
	char read[n+1];
	scanf(" %s",read);
	for(int i = 0;i < t;++i){
		int change = 0;
		for(int j = 0; j < n-1;++j){
			if(read[j] < read[j+1]){
				char temp = read[j];
				read[j] = read[j+1];
				read[j+1] = temp;
				++j;
				change = 1;
			}
		}
		if(change == 0)
			break;
	}
	printf("%s\n",read);
	return 0;
}