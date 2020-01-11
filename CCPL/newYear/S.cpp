#include<bits/stdc++.h>
using namespace std;


pair<string,string> rules[100];
int ans = 1000000000;
int ru;
string to;

bool suf(string &check, int va){
    if(rules[va].first.size() > check.size())return 0;
    for(int i = check.size()-1, k = rules[va].first.size()-1; k > -1;--i,--k){
        if(check[i] != rules[va].first[k]) return 0;
    }
    return 1;
}

int solve(string &s, unordered_map<string,int> &dp){
    if(dp.count(s)) return dp[s];
    dp[s] = 1000000000;
    if(s.compare(to) == 0) return dp[s] = 0;
    for(int i = 0; i < ru;++i){
        if(suf(s,i)){
            string send = s.substr(0,s.size()-rules[i].second.size()) + rules[i].second;
            dp[s] = min(solve(send,dp) +1,dp[s]);
        }
    }
    return dp[s];
}


int main(){
    string from;
    int cas = 1;
    while(1){
        cin >> from;
        if(from[0] == '.')break;
        cin >> to >> ru;
        for(int i = 0; i < ru;++i)
            cin >> rules[i].first >> rules[i].second;
        unordered_map<string,int> dp;
        int ans = solve(from,dp);
        if(ans >= 1000000000) printf("Case %d: No solution\n",cas++);
        else printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
