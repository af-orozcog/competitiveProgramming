#include<bits/stdc++.h>
using namespace std;

bool checkPosi(int where, char let, vector<char> &see, vector<int> &check){
    int val = 0;
    for(int i = 0; i < see.size();++i){
        if(see[i] != '@' && let < see[i]){
            val += abs(i-where);
        }
    }
    return check[where] == val;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string see;
        int m;
        cin >> see >> m;
        vector<int> ar(m);
        map<char,int> let;
        for(auto va:see)
            ++let[va];
        for(int i = 0; i < m;++i) cin >> ar[i];
        vector<char> ans(m,'@');
        for(auto it = let.rbegin(); it != let.rend();++it){
            while(it->second){
                for(int i = 0; i < ans.size();++i){
                    if(ans[i] == '@'){
                        if(checkPosi(i,it->first,ans,ar)){
                            ans[i] = it->first;
                            break;
                        }
                    }
                }
                --it->second;
            }
        }
        for(auto va:ans)
            cout << va;
        cout << "\n";
    }
    return 0;
}
