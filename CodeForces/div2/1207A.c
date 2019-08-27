#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int b,p,f,h,c;
		scanf(" %d %d %d %d %d",&b,&p,&f,&h,&c);
		int div = b >> 1;
		int ans = 0;
		if(h > c){
			ans += min(div,p)*h;
			ans +=min((b-min(div,p))>>1,f -min(div,p))*c;
		}
		else{
			ans += min(div,f)*c;
			ans +=min((b-min(div,f))>>1,p -min(div,f))*c;
		}
		printf("%d\n",ans);
	}
	return 0;
}