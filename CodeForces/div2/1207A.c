#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int b,p,f,h,c;
		scanf(" %d %d %d %d %d",&b,&p,&f,&h,&c);
		int ans = 0;
		int use = b >> 1;
		if(h > c){
			ans += min(use,p)*h;
			use -= min(use,p);
			ans += min(use,f)*c;
		}
		else if(c > h){
			ans += min(use,f)*c;
			use -= min(use,f);
			ans += min(use,p)*h;
		}
		else{
			ans += min(use,p)*h;
			use -= min(use,p);
			ans += min(use,f)*c;
		}
		printf("%d\n",ans);
	}
	return 0;
}