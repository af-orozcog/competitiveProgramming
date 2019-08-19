/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>

struct pair
{
	int first;
	int second;
};

int main(){
	int siz;
	scanf(" %d",&siz);
	struct pair teams[siz];
	for(int i = 0; i < siz;++i){
		int home,guest;
		scanf(" %d %d",&home,&guest);
		teams[i].first = home;
		teams[i].second = guest;
	}
	int ans = 0;
	for(int i = 0; i < siz;++i){
		for(int j = 0; j < siz;++j){
			if(i == j)
				continue;
			if(teams[i].first == teams[j].second)
				++ans;
		}
	}
	printf("%d\n",ans);
}