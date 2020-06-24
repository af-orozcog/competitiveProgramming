#include<bits/Stdc++.h>
#define ll long long
using namespace std;

ll mod1 = 1000000007, mod2 = 1000000009;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        unordered_set<ll> dif;
        string re;
        cin >> re;
        for(int i = 0; i < re.size();++i){
            ll va1,va2;
            va1 = va2 = 0;
            for(int j = i; j < re.size();++j){
                va1 *= 31ll;
                va2 *= 31ll;
                va1 += (re[j]-'A')+1;
                va2 += (re[j]-'A')+1;
                if(va1 >= mod1) va1 %= mod1;
                if(va2 >= mod2) va2 %= mod2;
                dif.insert((va1<<32) + va2);
            }
        }
        cout << dif.size() << "\n";
    }
}
