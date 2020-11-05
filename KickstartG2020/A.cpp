#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    int cas = 1;
    while(t--){
        string see;
        cin>> see;
        ll start = 0;
        ll ans = 0;
        for(int i = see.size()-1; i > -1;--i){
            string comp1 = see.substr(i,5);
            string comp2 = see.substr(i,4);
            if(comp1 == "START") ++start;
            if(comp2 == "KICK") ans += start;
        }
        cout << "Case #" << cas++ << ": " << ans << "\n";
    }
    return 0;
}
