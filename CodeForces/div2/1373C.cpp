#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string re;
        cin >> re;
        int num = 0;
        int ma = 0;
        vector<int> dp(re.size(),0);
        for(int i = 0; i < re.size();++i){
            dp[i] = num;
            if(re[i] == '+')++ma;
            if(re[i] == '-')--ma;
            if(ma < 0) ma = 0,++num;
        }
        ll ans = 0;
        for(auto va:dp){
            ans += (ll)(num-va)+1ll;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
