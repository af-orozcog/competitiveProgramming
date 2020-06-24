#include<bits/stdc++.h>
using namespace std;

int difference(string &a, string &b){
    int ans = 0;
    for(int i = 0; i < a.size();++i)
        if(a[i] != b[i]) ++ans;
    return ans;
}

int main(){
    int t;
    cin >> t;
    vector<string> see(t);
    vector<set<int>> dp(t);
    for(int i = 0; i < t;++i) cin >> see[i];
    int anss = 1;
    for(int i = t-1; i > -1;--i){
        set<int> works;
        set<int> works2;
        for(int j = i + 1; j < t;++j){
            if(difference(see[i],see[j]))
                works.insert(j);
        }
        set<int> ans;
        if(works.size() == 0){
            dp[i] = ans;continue;
        }
        for(auto va: works){
            set<int> see = dp[va];
            if(see.size() == 0) continue;
            set<int> intersect;
            set_intersection(works.begin(),works.end(),see.begin(),see.end(),inserter(intersect,intersect.begin()));
            if(intersect.size() > ans.size()) ans = intersect;
        }
        dp[i] = ans;
        anss = max(anss,(int)ans.size());
    }
    cout << anss << "\n";
    return 0;
}
