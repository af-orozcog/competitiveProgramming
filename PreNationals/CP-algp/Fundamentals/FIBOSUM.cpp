#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MOD = 1000000007;

pl fib(int n){
    if(!n) return {0,1};
    pl imp = fib(n>>1);
    ll first = imp.second<<1;
    if(first >= MOD) first -= MOD;
    first -= imp.first;
    if(first < 0) first += MOD;
    first *= imp.first;
    if(first >= MOD) first %= MOD;
    ll second = imp.first*imp.first;
    if(second >= MOD) second %= MOD;
    second += (imp.second*imp.second)%MOD;
    if(second >= MOD) second -= MOD;
    if(n&1){
        ll see = first+second;
        if(see >= MOD) see -= MOD;
        return {second,see};
    }
    else return {first,second};
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        ll see2 = fib(b+2).first;
        --see2;
        if(see2 < 0) see2 += MOD;
        ll see1 = fib(a+1).first;
        --see1;
        if(see1 < 0) see1 += MOD;
        ll ans = see2 - see1;
        if(ans < 0) ans += MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
