#include<bits/stdc++.h>
#define ll long long
using namespace std;

int importants[] = {-9,0,9};

bool neighbors(char a, char b){
    int see1 = a-'a';
    int see2 = b-'a';
    for(int i = 0; i < 3;++i){
        for(int j = -1; j < 2;++j){
            int comp = see1+importants[i]+j;
            if(comp == see2) return 1;
        }
    }
    return 0;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        if(a.size() != b.size()){
            cout << "3\n";
            continue;
        }
        bool eq = 1, ide = 1;
        for(int i = 0; i < a.size() && (eq || ide);++i){
            if(a[i] != b[i])
                eq = 0;
                ide = neighbors(a[i],b[i]);
        }
        if(eq) cout << 1 << "\n";
        else if(ide) cout << 2 << "\n";
        else cout << 3 << "\n";
    }
    return 0;
}
