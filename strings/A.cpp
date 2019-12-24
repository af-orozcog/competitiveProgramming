#include<bits/stdc++.h>
using namespace std;

map<int,int> z_algorithm (string &s) {
  int n = s.size();
  vector<int> z(n);
  z[0] = n;
  int x = 0, y = 0;
  for(int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      x = i, y = i+z[i], z[i]++;
  }
  map<int,int> fr;
  ++fr[n];
  for(int i = n-1;i > 0;--i){
    if(z[i] != 0){
        if(z[i] == n - i) ++fr[z[i]];
        else{
            auto it = fr.lower_bound(z[i]);
            if((*it).first > z[i]){
                if(it == fr.begin()) continue;
                else --it;
            }
            ++fr[(*it).first];
        }
    }
  }
  return fr;
}

int main(){
    string re;
    cin >> re;
    map<int,int> fr = z_algorithm(re);
    int cum = 0;
    vector<pair<int,int>> ans;
    for(auto it = fr.rbegin(); it != fr.rend();++it){
        ans.push_back({(*it).first,(*it).second+cum});
        cum += (*it).second;
    }
    cout << ans.size() << endl;
    for(int i = ans.size()-1; i > -1;--i)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
