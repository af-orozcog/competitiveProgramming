#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n;
    cin >> n;
    vector<string> operations(n);
    for(int i = 0; i < n;++i) cin >> operations[i];
    ll dp[2][n+1];
    dp[0][0] = dp[1][0] = 1;
    for(int i = 1; i <= n;++i){
        if(operations[i-1] == "AND"){
            dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[0][i-1];
            dp[1][i] = dp[1][i-1];
        }
        else{
            dp[0][i] = dp[0][i-1];
            dp[1][i] = dp[1][i-1] + dp[0][i-1] + dp[1][i-1];
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}
