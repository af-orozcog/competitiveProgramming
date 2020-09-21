#include<stdio.h>

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    int inter = n*m;
    int turn = 1;
    while(inter){
        ++turn;
        turn &= 1;
        --n,--m;
        inter -= n+m+1;
    }
    if(!turn) puts("Akshat");
    else puts("Malvika");
    return 0;
}
