#include<stdio.h>

int prime(int num){
    if(num == 1) return 0;
    for(int i = 2; i*i <= num;++i){
        if(num%i == 0) return 0;
    }
    return 1;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        for(int i = a; i < b+1;++i){
            if(prime(i))printf("%d\n",i);
        }
        if(t)puts("");
    }
    return 0;
}
