#include<bits/stdc++.h>
#define ll long long

using namespace std;

int mod(ll x,ll y){
    //cout << x << endl;
    if(x % y < 0) return (x%y)+y;
    return x % y;
}

int main(){
    ll n,m;
    cin >> n >> m;
    ll sum1 = 0,sum2 = 0;
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        sum1 += (ll)va;
    }
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        sum2 += (ll)va;
    }
    //cout << sum1 << " " << sum2 << endl;
    ll got = mod(sum2-sum1,m);
    //cout << got << endl;
    n = n%m;
    for(ll x = 0; x < m;++x){
        if((n*x)%m == got){
            cout << x << endl;return 0;}
    }
    return 0;
}
