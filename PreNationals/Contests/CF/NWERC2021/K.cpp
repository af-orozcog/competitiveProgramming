#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    set<char> ans;
    int i = 0, j = 0;
    for(; i < a.size();){
        if(a[i] != b[j]){
            ans.insert(b[j]);
            ++j;
        }
        else ++i,++j;
    }
    if(j != b.size()) ans.insert(b.back());
    string dAns = "";
    for(auto va:ans) dAns += va;
    cout << dAns << "\n";
}
