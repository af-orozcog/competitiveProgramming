#include<bits/stdc++.h>
#define ll long long
using namespace std;

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

int main(){
    int t;
    cin >> t;
    while(t--){
        string see;
        cin >> see;
        string co = see;
        reverse(co.begin(),co.end());
        string send = see + "$" + co;
        vector<int> z = z_algorithm(send);
        string ans = see.substr(0,1);
        for(int i = see.size()+1; i < z.size();++i){
            if(z[i] > ans.size()){
                ans = see.substr(0,z[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << "\n";
    }
    return 0;
}
