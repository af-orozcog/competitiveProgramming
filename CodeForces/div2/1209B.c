#include<stdio.h>
#define max(x,y)(x > y ? x:y)

int main(){
	int n;
	scanf(" %d",&n);
	short state[n];
	for(int i = 0; i < n;++i){
		char va;scanf(" %c",&va);
		state[i] = va-'0';
	}
	int from[n],pe[n];
	for(int i = 0; i < n;++i) scanf(" %d %d",&pe[i],&from[i]);
	int ans = 0;
	for(int i = 0; i < 1100;++i){
		int count = 0;
		for(int j = 0; j < n;++j){
			if(state[j])
				++count;
		}
		ans = max(count,ans);
		for(int j = 0; j < n;++j){
			if(i >= from[j] && (i - from[j]) % pe[j] == 0)
				state[j] = (state[j] + 1)%2;
			//printf("%d ",state[j]);
		}
		//puts("");
	}
	printf("%d\n",ans);
	return 0;
}