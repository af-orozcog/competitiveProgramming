#include<bits/stdc++.h>
#define ll long long
using namespace std;


char machete(string &see, int let[]){
    for(int i = see.size()-1; i > -1;--i){
        for(int j = see[i]-';
    }
}


int main(){
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(b.size() > a.size()){
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout << a << "\n";
        return 0;
    }
    string ans = "";
    int let[10];
    memset(let,0,sizeof(let));
    for(auto va:a) ++let[va-'0'];
    bool nor = 1;
    for(int i = 0; i < b.size();++i){
        if(nor){
            bool added = 0;
            for(int j = b[i]-'0'; j > -1;--j){
                if(let[j]){
                    ans += ('0'+j);
                    --let[j];
                    added = 1;
                    break;
                }
            }
            if(ans.back() < b[i]) nor = 0;
        }
        else{
            for(int j = 9; j > -1;--j){
                if(let[j]){
                    ans += (j+'0');
                    --let[j];
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
