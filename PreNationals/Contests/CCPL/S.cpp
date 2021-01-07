#include<bits/stdc++.h>
using namespace std;

int answer(string &see){
    vector<int> kmp(see.size(),0);
    int border = 0;
    int ans = 1;
    for(int i = 1; i < see.size();++i){
        while(border && see[i] != see[border])
            border = kmp[border-1];
        if(see[border] == see[i])
            ++border;
        kmp[i] = border;
        ans = max(ans,border);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string use;
        cin >> use;
        string lel = use;
        reverse(lel.begin(),lel.end());
        string send = use + "$" + lel;
        int val = answer(send);
        string ans = use.substr(0,val);
        reverse(ans.begin(),ans.end());
        cout << ans << "\n";
    }
    return 0;
}
