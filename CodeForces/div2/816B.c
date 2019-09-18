/**
* Why the fuck am I doing this Shit
* Do a double fucking BIT, sorry just one- prefix sums
*/
#include<stdio.h>
#include<string.h>

int nums[200002];
int count[200002];

int main(){
	int n,k,q;
	scanf(" %d %d %d",&n,&k,&q);
	for(int i = 0; i< n;++i){
		int a,b;
		scanf(" %d %d",&a,&b);
		++count[a];
		--count[b+1];
	}
	int sum = 0;
	for(int i = 1; i < 200002;++i){
		sum += count[i];
		if(sum >= k)
			nums[i]++;
		nums[i] += nums[i-1];
	}
	while(q--){
		int a,b;
		scanf(" %d %d",&a,&b);
		printf("%d\n",nums[b]-nums[a-1]);
	}
	return 0;
}