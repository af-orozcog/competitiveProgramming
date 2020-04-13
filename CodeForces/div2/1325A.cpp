#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll x;
        scanf(" %lld",&x);
        if(x&1) printf("1 %lld\n",x-1);
        else printf("%lld %lld\n",x>>1,x>>1);
    }
    return 0;
}
