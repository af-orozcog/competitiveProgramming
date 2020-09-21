#include<stdio.h>
#define min(x,y)(x < y? x:y)

int main(){
    int n,k,l,c,d,p,nl,np;
    scanf(" %d %d %d %d %d %d %d %d",&n,&k,&l,&c,&d,&p,&nl,&np);
    int totalM = k*l;
    int slices = c*d;
    int ans = min(totalM/nl,min(p/np,slices))/n;
    printf("%d\n",ans);
    return 0;
}
