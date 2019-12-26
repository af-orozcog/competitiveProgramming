#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a,b;
    cin >> a >> b;
    ll ans = 1;
    for(ll i = 1; i <= min(a,b);++i)ans*= i;
    cout << ans << endl;
    return 0;
}
