#include<iostream>
#include<string>
#include<vector>
#define ll long long
using namespace std;

int main(){
    string re;
    while(cin >> re){
        if(re.size() == 1 && re[0] == '0') break;
        vector<ll> dp(re.size());
        dp[0] = 1;
        dp[1] = 1;
        if(re.size() > 1 && (re[0]-'0')*10 + re[1]-'0' < 27 && re[1]!= '0')
            dp[1] += 1;
        for(int i = 2; i < re.size();++i){
            int num = (re[i-1]-'0')*10 + re[i]-'0';
            dp[i] = 0;
            if(num < 27 && re[i-1] != '0')
                dp[i] += dp[i-2];
            if(re[i] != '0')
                dp[i] += dp[i-1];
        }
        printf("%lld\n",dp[re.size()-1]);
    }
    return 0;
}
