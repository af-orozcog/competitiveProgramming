#include<stdio.h>

int main(){
    int h,a;
    scanf(" %d %d",&h,&a);
    printf("%d\n",h/a +(h%a?1:0));
    return 0;
}
