#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    string see;
    cin >> see;
    string ot = "heidi";
    int imp = 0;
    for(int i = 0; i < see.size() && imp < ot.size();++i){
        if(see[i] == ot[imp]) ++imp;
    }

    if(ot.size() == imp) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
