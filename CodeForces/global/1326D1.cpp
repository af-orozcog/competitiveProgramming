#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

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
    scanf(" %d",&t);
    while(t--){
        string re;
        cin >> re;
        string revel = re, cpn2 = re;
        reverse(revel.begin(),revel.end());
        if(re.size() == 1){
            cout << re << "\n";
            continue;
        }
        int i = 0, j = re.size()-1;
        string eq = "";
        while(i <= j && re[i] == re[j]){
            eq += re[i];
            ++i,--j;
        }
        if(i > j)cpn2 = "", eq = "";
        else
            cpn2 = cpn2.substr(i,j-i+1);
        //cout << "cpn2 is " << cpn2 << "\n";
        string cpr2 = cpn2;
        string eqr = eq;
        reverse(eqr.begin(),eqr.end());
        reverse(cpr2.begin(),cpr2.end());
        string see1 = re + "$" + revel;
        vector<int> z = z_algorithm(see1);
        int ans = eq.size()+eq.size();
        string show = eq+eqr;
        if(ans == 0){
            ans = 1;
            show = "";
            show += re[0];
        }
        //cout << "eq is " <<eq << endl;
        for(int i = re.size()+1; i < see1.size();++i){
            if(z[i] == (int)see1.size()-i){
                if(ans < z[i]) show = re.substr(0,z[i]), ans = z[i];
                break;
            }
        }
        string see2 = revel + "$" + re;
        z = z_algorithm(see2);
        for(int i = re.size()+1; i < see2.size();++i){
            if(z[i] == (int)see1.size()-i){
                if(ans < z[i]) show = revel.substr(0,z[i]), ans = z[i];
                break;
            }
        }
        string see3 = cpn2 + "$" + cpr2;
        //cout << "see3 is " << see3 << "\n";
        z = z_algorithm(see3);
        for(int i = cpn2.size()+1; i < see3.size();++i){
            //cout << i << " " << z[i] << endl;
            if(z[i] == (int)see3.size()-i){
                //out <<" entro???\n";
                int tama = eq.size() + eq.size();
                if(ans < z[i] + tama){
                  //  cout << "wut\n";
                   // cout << cpn2.substr(0,z[i]) << endl;
                    show = eq + cpn2.substr(0,z[i])+eqr, ans = z[i]+tama;
                }
                break;
            }
        }
        //cout << show << endl;
        string see4 = cpr2 + "$" + cpn2;
        z = z_algorithm(see4);
        for(int i = cpn2.size()+1; i < see4.size();++i){
            if(z[i] == (int)see4.size()-i){
                int tama = eq.size() + eq.size();
                if(ans < z[i] + tama) show = eq + cpr2.substr(0,z[i])+eqr, ans = z[i]+tama;
                break;
            }
        }
        cout << show << "\n";
    }
    return 0;
}
