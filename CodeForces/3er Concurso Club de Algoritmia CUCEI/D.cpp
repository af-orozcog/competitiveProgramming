#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string pos;
        getline(cin,pos);
        set<char> imp;
        for(int i = 0; i < 26;++i) imp.insert('a'+i);
        for(auto va:pos){
            char see = tolower(va);
            imp.erase(see);
        }
        if(imp.size()) puts("How cute, such a prankster");
        else puts("I expel you PAZUZU");
    }
    return 0;
}
