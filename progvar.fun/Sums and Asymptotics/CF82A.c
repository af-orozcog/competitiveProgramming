#include<stdio.h>
#include<string.h>
#define ll long long

int main(){
    char ans[5][20] = { "Sheldon",
                        "Leonard",
                        "Penny",
                        "Rajesh",
                        "Howard"
    };
    ll n;
    scanf(" %lld",&n);
    int who = 0;
    ll vals[5] = {1,1,1,1,1};
    while(n > 0ll){
        n -= vals[who];
        vals[who] <<= 1;
        ++who;
        if(who == 5) who = 0;
    }
    --who;
    if(who == -1) who += 5;
    printf("%s\n",ans[who]);
    return 0;
}
