#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
    int n,v;
    scanf(" %d %d",&n,&v);
    int i = 1;
    int cost = min(v*1,(n-1)*i);
    ++i;
    while(i <= n-v){
        cost += i;
        ++i;
    }
    printf("%d\n",cost);
    return 0;
}
