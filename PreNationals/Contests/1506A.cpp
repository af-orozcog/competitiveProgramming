#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,m,x;
        scanf(" %lld %lld %lld",&n,&m,&x);
        --x;
        ll col = x/n;
        ll row = (x%n);
        printf("%lld\n",(row*m+(col+1LL)));
    }
    return 0;
}
