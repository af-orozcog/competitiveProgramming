#include<bits/stdc++.h>
using namespace std;

int bound;

bool z_algorithm (string &s, int si) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for(int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      x = i, y = i+z[i], z[i]++;
  }
  z[0] = 0;
  int co =0;
  for(int i = 1; i < n;++i){
    if(z[i] >= si) ++co;
  }
  return co>= bound;
}

int main(){
    string re1,re2;
    getline(cin,re1);getline(cin,re2);
    scanf(" %d",&bound);
    int lo = 1,hi = re2.size(),ans = -1;
    string send = re2 + "$" + re1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(z_algorithm(send,mid)){
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid -1;
    }
    if(ans == -1)puts("IMPOSSIBLE");
    else cout << re2.substr(0,ans)<< "\n";
    return 0;
}
