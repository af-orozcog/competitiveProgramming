#include<bits/stdc++.h>
using namespace std;

vector<int> z_algorithm (string &s){
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
    int n;
    scanf(" %d",&n);
    string re1,re2;
    cin >> re1 >> re2;
    re2 = re2+ re2;
    string send = re1 + "$" +re2;
    vector<int> z = z_algorithm(send);
    int ma = 0, who;
    for(int i = re1.size()+1,j = 0; j < n;++i,++j){
        if(z[i] > ma){
            ma = z[i];
            who = j;
        }
    }
    cout << who << "\n";
    return 0;
}
