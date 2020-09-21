#include<stdio.h>

int main(){
    int a,b;
    scanf(" %d %d",&a,&b);
    int less = 1;
    int turn = 0;
    while(1){
        if(!turn){
            a-=less;
            if(a < 0){
                puts("Vladik");return 0;
            }
        }
        else{
            b-=less;
            if(b < 0){
                puts("Valera");return 0;
            }
        }
        turn = (turn+1)&1;
        ++less;
    }
    return 0;
}
