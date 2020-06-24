#include<bits/stdc++.h>
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
    string line;
    while(getline(cin,line)){
        string co = line;
        reverse(co.begin(),co.end());
        string send = co + "$" + line;
        vector<int> z = z_algorithm(send);
        int where = co.size()-1;
        for(int i = co.size()+1, j = 0; i < z.size();++i,++j){
            if(z[i] + i == z.size()){
                where = j-1; break;
            }
        }
        string ans = line;
        for(int i = where; i > -1;--i)
            ans += ans[i];
        cout << ans << "\n";
    }
    return 0;
}
