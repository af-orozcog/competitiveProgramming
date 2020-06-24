#include<bits/stdc++.h>
using namespace std;

int dp[3000][3000];

int main(){
    string s,t;
    cin >> s >> t;
    for(int i = 0; i < s.size();++i){
        dp[0][i] = (s[i] == t[0]);
        if(i > 0) dp[0][i] = max(dp[0][i],dp[0][i-1]);
    }
    for(int i = 0; i < t.size();++i){
        dp[i][0] = (s[0] == t[i]);
        if(i > 0) dp[i][0] = max(dp[i][0],dp[i-1][0]);
    }
    for(int i = 1; i < s.size();++i){
        for(int j = 1; j < t.size();++j){
            if(s[i] == t[j]) dp[j][i] = 1 + dp[j-1][i-1];
            else dp[j][i] = max(dp[j-1][i],dp[j][i-1]);
        }
    }
    string ans = "";
    int i = t.size()-1,j = s.size()-1;
    while(i > -1 && j > -1){
        if(t[i] == s[j]) ans += t[i],--i,--j;
        else{
            if(i > 0 && j > 0){
                if(dp[i-1][j] > dp[i][j-1])
                    --i;
                else
                    --j;
            }
            else if(i > 0) --i;
            else --j;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
    return 0;
}
