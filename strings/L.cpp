#include<bits/stdc++.h>
using namespace std;

bool z_algorithm (string &s, int in) {
  int n = s.size();
  vector<int> z(n);
  z[0] = n;
  int x = 0, y = 0;
  for(int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      x = i, y = i+z[i], z[i]++;
  }
  for(int i = 1; i < n;++i){
    if(z[i] == in) return 1;
  }
  return 0;
}
int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        string ini;
        cin >> ini;
        int q;scanf(" %d",&q);
        while(q--){
            string ru; cin >> ru;
            string sen = ru +"$" + ini;
            if(z_algorithm(sen,ru.size())) puts("y");
            else puts("n");
        }
    }
    return 0;
}
