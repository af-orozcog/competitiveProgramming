#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[26][26];
ll co[26];

int main(){
    string re;
    cin >> re;
    for(int i = 0; i < re.size();++i){
        for(int j = 0; j < 26;++j)
            dp[re[i]-'a'][j] += co[j];
        ++co[re[i]-'a'];
    }
    ll ans = 0;
    for(int i = 0; i < 26;++i) ans = max(ans,co[i]);
    for(int i = 0; i < 26;++i){
        for(int j = 0; j < 26;++j)
            ans = max(ans,dp[i][j]);
    }
    printf("%lld\n",ans);
    return 0;
}
