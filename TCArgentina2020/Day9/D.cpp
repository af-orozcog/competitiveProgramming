#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define SIZE 1000000 + 1
#define pb push_back
int P[SIZE * 2];
// Transform S into new string with special characters inserted.
string convertToNewString(string &s) {
    string newString = "@";
    for (int i = 0; i < s.size(); i++) {
        newString.pb('#');
        newString.pb(s[i]);
    }
    newString += "#$";
    return newString;
}
//Construye el arreglo P en donde en cada posición esta el tmño de la Palindroma
//centrada alli mas grande
string findPalindromes(string &s) {
    string Q = convertToNewString(s);
    int c = 0, r = 0;
    //cout<<Q<<"\n";
    for (int i = 1; i < Q.size() - 1; i++) {
        int iMirror = c - (i - c);
        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }
        if (i + P[i] > r) {
            c = i;
            r = i + P[i];
        }
    }
    return Q;
}
vector<pair<string,int>> longestPalindromeSubstring(string &s){
    string Q = findPalindromes(s);
    vector<pair<string,int>> send;
    for (int i = 1; i < Q.size() - 1; i++) {
        if (P[i] > 0) {
            int maxPalindrome = P[i];
            int centerIndex = i;
            string ini = s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
            int from = (centerIndex - 1 - maxPalindrome) / 2;
            while(ini.size()){
                send.push_back({ini,from});
                ini.pop_back();
                if(ini.size()) ini.erase(ini.begin());
                ++from;
            }
        }
    }
    sort(send.begin(),send.end());
    return send;
}
const ll mul = 100001;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >>q;
    string s;
    cin >> s;
    vector<pair<string,int>> see = longestPalindromeSubstring(s);
    ll dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n;++i){
        dp[i] = dp[i-1]*mul;
        if(dp[i] >= mod)
            dp[i] %= mod;
    }
    ll imp[n];
    imp[0] = s[0];
    for(int i = 1; i < n;++i){
        imp[i] = imp[i-1]*mul;
        if(imp[i] >= mod) imp[i] %= mod;
        imp[i] += s[i];
        if(imp[i] >= mod) imp[i] -= mod;
    }
    while(q--){
        int k;
        cin >> k;
        --k;
        if(k >= (int)see.size()){puts("-1");continue;}
        ll ans = imp[(int)see[k].first.size()+see[k].second-1];
        ll les = 0;
        if(see[k].second > 0)
            les = imp[see[k].second-1]*dp[(int)see[k].first.size()];
        if(les >= mod) les %= mod;
        ans -= les;
        if(ans < 0) ans += mod;
        printf("%lld\n",ans);
    }
    return 0;
}
