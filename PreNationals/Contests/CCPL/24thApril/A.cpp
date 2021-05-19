#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll valuesDown(ll val,ll n){
    return val + n;
}

ll valuesUp(ll val, ll n){
    return val - n;
}

ll right(ll val){ return val + 1;}

ll left(ll val){return val - 1;}

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    ll ans = 1;
    ll actual = 1;
    while(k--){
        char M; scanf(" %c",&M);
        if(M == 'D') actual = valuesDown(actual,n);
        else if(M == 'U') actual = valuesUp(actual,n);
        else if(M == 'R') actual = right(actual);
        else actual = left(actual);
        ans += actual;
    }
    printf("%lld\n",ans);
    return 0;
}
