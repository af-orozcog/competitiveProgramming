#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    ll n;
    cin >> n;
    cout << 4ll*fastSum(n>>1) - fastSum(n) << "\n";
    return 0;
}
