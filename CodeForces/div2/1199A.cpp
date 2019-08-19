/**
* about to get grey
*/
#include<iostream>

using namespace std;

int main(){
	int n,x,y;
	scanf(" %d %d %d",&n,&x,&y);
	int num[n];
	for(int i = 0; i < n;++i)
		scanf(" %d",&num[i]);
	for(int i = 0; i < n;++i){
		int le = 1,ri = 1;
		bool ans = true;
		while(i +ri < n && ri <= y){
			if(num[i+ri] <= num[i]){
				ans = false;
				break;
			}
			++ri;
		}
		if(!ans)
			continue;
		while(i - le >= 0 && le <= x){
			if(num[i-le] <= num[i]){
				ans = false;
				break;
			}
			++le;
		}
		if(ans){
			printf("%d\n",i+1);
			return 0;
		}
	}
	return 0;
}