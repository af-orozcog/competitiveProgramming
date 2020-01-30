#include<stdio.h>
#define ll long long

ll va[41];

int pre(){
    for(int i = 0;i < 41;++i){
        ll temp = 0;
        for(int j = 1; j <= i;++j)
            temp += ((ll)1<<j);
        va[i] = temp + 1ll;
    }
    return 1;
}

int main(){
    pre();
    ll h;
    scanf(" %lld",&h);
    int ma = -1;
    while(h){
        ++ma;
        h>>=1;
    }
    printf("%lld\n",va[ma]);
    return 0;
}
