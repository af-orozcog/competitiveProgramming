#include <stdio.h>
#define min(x,y)(x < y?x:y)
#define max(x,y)(x > y? x:y)
int main(){
    int q;
    scanf(" %d",&q);
    while(q--){
    	int c,m,x;
    	scanf(" %d %d %d",&c,&m,&x);
    	int ans = min(c,min(m,x));
    	c -= ans; m -= ans;
        if(m > c){
    	   int temp = min(c,m>>1);
            c -= temp;
            m -= (temp<<1);
            ans += temp;
            temp = min(c>>1,m);
            ans += temp;
        }
        else{
            int temp = min(c>>1,m);;
            c -= (temp<<1);
            m -= temp;
            ans += temp;
            temp = min(c,m>>1);
            ans += temp;
        }
    	printf("%d\n",ans);
    }
    return 0;
}