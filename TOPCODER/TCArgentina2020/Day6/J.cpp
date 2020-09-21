#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll MAXN = 1000000000ll;

ll dp[26][26];

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    if(str1.size() != str2.size()){puts("-1");return 0;}
    int n;
    cin >> n;
    for(int i = 0; i < 26;++i){
        for(int j = 0; j < 26;++j)
            dp[i][j] = MAXN;
        dp[i][i] = 0ll;
    }
    while(n--){
        char a,b; ll cost;
        cin >> a >> b >> cost;
        dp[a-'a'][b-'a'] = min(cost,dp[a-'a'][b-'a']);
    }
    for(int k = 0; k < 26;++k)
        for(int i = 0; i < 26;++i)
            for(int j = 0; j < 26;++j)
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
    string ans = "";
    ll cost = 0;
    for(int i = 0; i < str1.size();++i){
        ll add = MAXN;
        char who = 'a';
        for(int j = 0; j < 26;++j){
            ll temp = dp[str1[i]-'a'][j] + dp[str2[i]-'a'][j];
            if(temp < add)
                add = temp,who = 'a'+j;
        }
        if(add == MAXN){puts("-1");return 0;}
        ans+=who;
        cost += add;
    }
    cout << cost <<"\n"<<ans<<"\n";
    return 0;
}
