#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> tuo;

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
    int n;
    vector<ll> answer(1000001,0);
    for(int i = 1; i <= 1000000;++i){
        for(int j = i*2; j <= 1000000; j+= i){
            answer[j] += (ll)i*(ll)tuo[j/i];
        }
    }
    for(int i = 3; i <= 1000000; ++i)
        answer[i] += answer[i-1];
    while(scanf(" %d",&n) && n){

        printf("%lld\n",answer[n]);
    }
    return 0;
}
