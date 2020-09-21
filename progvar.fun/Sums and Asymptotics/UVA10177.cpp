#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    ll n;
    while(scanf(" %lld",&n) == 1){
        ll ans1 = (2ll*n+1ll)*n*(n+1ll)/6ll,ans2 = fastSum(n)*fastSum(n), ans3 = fastSum(n)*fastSum(n), ans4 = fastSum(n)*fastSum(n)*fastSum(n), ans5 = n*(n+1ll)*(6ll*n*n*n+9ll*n*n+n-1ll)/30ll, ans6 = fastSum(n)*fastSum(n)*fastSum(n)*fastSum(n);
        ans2 -= ans1,ans4-= ans3,ans6 -= ans5;
        printf("%lld %lld %lld %lld %lld %lld\n",ans1,ans2,ans3,ans4,ans5,ans6);
    }
    return 0;
}
