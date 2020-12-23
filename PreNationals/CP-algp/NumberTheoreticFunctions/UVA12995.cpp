#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tuo;

void phi(int n){
    tuo.resize(n+1);
    for(int i = 0; i <= n;++i)
        tuo[i] = i;

    for(int i = 2; i <= n;++i){
        if(tuo[i] == i){
            for(int j = i; j <= n; j+= i)
                tuo[j] -= tuo[j]/i;
        }
    }
}

int main(){
    phi(1000000);
    tuo[0] = tuo[1] = 0;
    for(int i = 3; i <= 1000000;++i)
        tuo[i] += tuo[i-1];
    int n;
    while(scanf(" %d",&n) && n){
        printf("%lld\n",tuo[n]);
    }
    return 0;
}
