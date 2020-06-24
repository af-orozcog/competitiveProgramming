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

bool palindrome(string &see){
    for(int i = 0, j = see.size()-1; i <= j;++i,--j)
        if(see[i] != see[j]) return false;
    return 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string re;
        cin >> re;
        string co = re;
        reverse(co.begin(),co.end());
        string send = co + "$" + re;
        vector<int> z = z_algorithm(send);
        int k = re.size()-1;
        int ans = 0;
        for(int i = (int)z.size()-1; i > (int)re.size()+1 && !ans;--i,--k){
            if(i+z[i] == z.size()){
                string check = re.substr(0,k);
                if(palindrome(check)) {cout << "alindrome\n";ans = 1;}
            }
        }
        if(!ans){
            if(palindrome(re)) cout << "palindrome\n";
            else cout << "simple\n";
        }
    }
    return 0;
}
