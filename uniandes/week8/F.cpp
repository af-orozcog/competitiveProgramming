#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    unordered_map<string,int> tr;
    vector<string> people;
    for(int i = 0; i < n;++i){
        string re;
        cin >> re;
        tr[re] = i;
        people.push_back(re);
    }
    vector<pair<int,int>> notUse;
    while(m--){
        string a,b;
        cin >> a >> b;
        notUse.push_back({tr[a],tr[b]});
    }
    int ans = 1;
    int who = 1;
    for(int i = 1; i < (1<<n);++i){
        bitset<32> check(i);
        bool good = 1;
        for(auto va:notUse){
            if(check[va.first] && check[va.second])
                good = 0;
        }
        if(good){
            if(ans < (int)check.count())
                ans = (int)check.count(), who = i;
        }
    }
    vector<string> names;
    bitset<32> check(who);
    for(int i = 0; i < 32;++i)
        if(check[i])
            names.push_back(people[i]);
    sort(names.begin(),names.end());
    cout << ans << "\n";
    for(auto va:names)
        cout << va << "\n";
    return 0;
}
