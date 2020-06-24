#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        string re;
        cin >> re;
        set<char> let;
        for(auto va:re)
            let.insert(va);
        if((int)let.size() == 1){
            cout << re << "\n";
            continue;
        }
        vector<char> ans;
        for(int i = 0; i < re.size()-1;++i){
            ans.push_back(re[i]);
            if(re[i] == re[i+1]){
                if(re[i] == '1')
                    ans.push_back('0');
                else ans.push_back('1');
            }
        }
        ans.push_back(re.back());
        for(auto va:ans)
            cout << va;
        cout << "\n";
    }
    return 0;
}
