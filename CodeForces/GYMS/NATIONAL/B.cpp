#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n;
    scanf(" %d",&n);
    while(n--){
        ll k,x;
        scanf(" %lld %lld",&k,&x);
        --x;
        --k;
        printf("%lld\n",9ll*k+x+1);
    }
    return 0;
}
