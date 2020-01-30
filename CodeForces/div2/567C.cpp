#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    unordered_map<ll, ll> dp[2];
    int n; ll k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 0; i < n;++i){
        ll temp; cin >> temp;
        if(temp% k == 0){
            ans += dp[1][temp/k];
            dp[1][temp] += dp[0][temp/k];
        }
        ++dp[0][temp];
    }
    cout << ans << "\n";
    return 0;
}
