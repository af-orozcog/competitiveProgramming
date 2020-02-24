#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    unordered_map<string,int> fr;
    vector<string> ans;
    int ma = 0;
    for(int i = 0; i < n;++i){
        string re; cin >> re;
        ++fr[re];
        if(fr[re] > ma){ma = fr[re];ans.clear();}
        if(fr[re] == ma) ans.push_back(re);
    }
    sort(ans.begin(),ans.end());
    for(auto va: ans) cout << va << "\n";
    return 0;
}
