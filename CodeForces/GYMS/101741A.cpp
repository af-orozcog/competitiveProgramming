#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in", "r", stdin);
    int n,q;
    cin >> n >> q;
    string re;
    cin >> re;
    while(q--){
        string que;
        cin >> que;
        string send = que + "$" + re;
        vector<int> z = z_algorithm(send);
        vector<int> dp((int)z.size()+1,0);
        for(int i = (int)z.size()-1; i > que.size();--i){
            if(z[i] == que.size()){
                dp[i] = 1;
                if(i+(int)que.size() < (int)z.size())
                    dp[i] += dp[i+(int)que.size()];
            }
            dp[i] = max(dp[i],dp[i+1]);
        }
        cout << dp[(int)que.size()+1] << "\n";
    }
    return 0;
}
