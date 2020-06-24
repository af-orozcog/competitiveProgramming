//hope to have a good performance to show Marie :)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        ll ans = 0;
        for(ll i = 3, j = 1; i <= n;i+=2ll,++j){
            ans += ((i<<1) + ((i-2ll)<<1))*j;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
