#include<stdio.h>
#define ll long long

ll n;

ll calc(ll level){
    if(!level) return 0;
    return (n-level)*level+1ll + calc(level-1);
}

int main(){
    scanf(" %lld",&n);
    printf("%lld\n",calc(n));
    return 0;
}
