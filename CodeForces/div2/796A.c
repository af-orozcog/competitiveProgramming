/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	--m;
	int houses[n];
	for(int i = 0; i < n;++i){
		scanf(" %d",(houses + i));
	}
	int left = m - 1;
	int right = m + 1;
	int answer;
	while(left >= 0 || right < n){
		if(left >= 0 && houses[left] > 0 && 
			houses[left] <= k){
			answer = left;
			break;
		}
		if(right < n && houses[right] > 0 &&
			houses[right] <= k){
			answer = right;
			break;
		}
		--left;
		++right;
	}
	answer = answer - m;
	answer = answer * 10;
	if(answer < 0)
		answer = -answer;
	printf("%d\n",answer);
	return 0;
}