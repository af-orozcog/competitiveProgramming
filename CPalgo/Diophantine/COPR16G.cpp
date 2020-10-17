#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        ll g = __gcd(a,b);
        if(g != 1){
            puts("-1");
            continue;
        }
        printf("%lld\n",a*b-a-b+1ll);
    }
    return 0;
}
