#include<stdio.h>

int main(){
	int siz;
	scanf(" %d",&siz);
	int ar[siz];
	for(int i = 0; i < siz;++i){
		scanf(" %d",&ar[i]);
	}
	int i = 0, j = siz -1;
	int min = -1;
	int st = 0;
	char answer[200001]; 
	while(i <= j){
		if(ar[i] <= min && ar[j] <= min)
			break;
		else if((ar[i] < ar[j] && ar[i] > min) ||(ar[j] < min && ar[i] > min)){
			min = ar[i];
			++i;
			answer[st] = 'L';
			++st;
		}
		else if(ar[j] > min){
			min = ar[j];
			--j;
			answer[st] = 'R';
			++st;
		}
		else
			break;
	}
	answer[st] = '\0';
	printf("%d\n",st);
	printf("%s\n",answer);
	return 0;
}