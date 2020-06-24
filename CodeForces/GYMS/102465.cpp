#include<bits/stdc++.h>
using namespace std;

int dp[702][702];
string see;

vector<int> z_algorithm (string &s) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for(int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      x = i, y = i+z[i], z[i]++;
  }
  return z;
}

bool check(string &a, string &b){
    string send = a + "$" + b;
    vector<int> z = z_algorithm(send);
    for(int i = (int)z.size()-(int)a.size(); i > a.size();i-=(int)a.size()){
        if(z[i] != (int)a.size()) return 0;
    }
    return 1;
}

int main(){
    int n;
    cin >> n >> see;
    for(int i = 0; i < 702;++i)
        for(int j = 0; j < 702;++j)
            dp[i][j] = 1000000000;
    for(int i = 0; i < see.size();++i)
        dp[i][i] = 1;
    for(int i = 1; i < (int)see.size();++i){
        for(int j = 0; j < see.size();++j){
            if(j+i >= see.size()) break;
            for(int k = j; k < j+i; ++k){
                if((j+i-k)%(k-j+1) == 0){
                    string a = see.substr(j,k-j+1);
                    string b = see.substr(k+1,(j+i-k));
                    if(check(a,b)) dp[j][j+i] = min(dp[j][j+i],dp[j][k]);
                }
                dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
            }
        }
    }
    cout << dp[0][(int)see.size()-1] << "\n";
    return 0;
}
