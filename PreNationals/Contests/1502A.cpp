#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    cin >> t;
    while(t--){
        string see;
        cin >> see;
        int i = 0, j = see.size()-1;
        while(i < j && see[i] == see[j]) ++i,--j;
        if(i < j){
            if(see[i] == 'a') see.insert(see.begin()+i,'a');
            else if(see[j] == 'a') see.insert(see.begin()+j,'a');
            else see.insert(see.begin()+i,'a');
            cout << "YES\n" << see << "\n";
            continue;
        }
        bool ans = 0;
        for(int i = 0; i < see.size() && !ans;++i){
            if(see[i] != 'a'){
                see.insert(see.begin()+i,'a');
                ans = 1;
            }
        }
        if(ans) cout << "YES\n" << see << "\n";
        else cout << "NO\n";
    }
    return 0;
}
