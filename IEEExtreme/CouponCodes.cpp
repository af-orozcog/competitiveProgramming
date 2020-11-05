#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    unordered_set<string> mp;
    int n;
    cin >> n;
    string store;
    ll ans = 0;
    for(int i = 0; i < n;++i){
        cin >> store;
        for(auto &va:store){
            if(va == '-') continue;
            char before = va;
            va = '*';
            if(mp.count(store)) ++ans;
            else mp.insert(store);
            va = before;
        }
    }
    cout << ans+1ll << "\n";
    return 0;
}
