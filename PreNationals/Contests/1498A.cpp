#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll sumD(ll val){
    int ans = 0;
    while(val){
        ans += (val%10);
        val /= 10;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        for(ll i = 0; i <= 10;++i){
            ll see = __gcd(n+i,sumD(n+i));
            if(see != 1){
                printf("%lld\n",n+i);
                break;
            }
        }
    }
    return 0;
}
