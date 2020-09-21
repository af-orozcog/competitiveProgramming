#include<bits/Stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    ll k,n,w;
    scanf(" %lld %lld %lld",&k,&n,&w);
    ll see = fastSum(w)*k;
    printf("%lld\n",max(0ll,see-n));
    return 0;
}
