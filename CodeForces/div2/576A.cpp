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
		while((i -le >= 0 && num[i-le]>num[i])|| (i + ri < n
		&& num[i+ri] > num[i])){
			++le;
			++ri;
		}
		if((i - le == 0) && (i + ri == n)){
			printf("%d\n",i+1);
			return 0;
		}
		if((i-le == 0) && (ri >= y)){
			printf("%d\n",i+1);
			return 0;
		}
		if((i +ri == n) && (le >= x)){
			printf("%d\n",i+1);
			return 0;
		}
		if(ri >= y && le >= x){
			printf("%d\n",i+1);
			return 0;
		}
	}
}