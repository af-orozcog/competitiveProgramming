#include<stdio.h>

int main(){
    int h,n;
    scanf(" %d %d",&h,&n);
    int su = 0;
    for(int i = 0; i < n;++i){
        int te;scanf(" %d",&te);
        su += te;
    }
    if(su >= h)puts("Yes");
    else puts("No");
    return 0;
}
