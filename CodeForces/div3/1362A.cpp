#include<bits/stdc++.h>
#define ll long long
using namespace std;

int val(ll n){
    int ans = -1;
    int co = 0;
    while(n){
        ++ans;
        if(n&1)++co;
        n >>= 1;
    }
    //cout << co << "\n";
    if(co > 1)return -1;
    //cout << ans << "\n";
    int wut = ans/3;
    ans -= (ans/3)*3;
    wut += ans/2;
    ans -= (ans/2)*2;
    wut += ans;
    return wut;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        if(a > b){
            if(a%b != 0) {puts("-1");continue;}
            ll see = a/b;
            int imp = val(see);
            printf("%d\n",imp);
        }
        else{
            if(b%a != 0) {puts("-1");continue;}
            ll see = b/a;
            int imp = val(see);
            printf("%d\n",imp);
        }
    }
    return 0;
}
