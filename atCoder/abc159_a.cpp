#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    printf("%lld\n",fastSum(max(n-1,0))+fastSum(max(m-1,0)));
    return 0;
}
