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
        bool see1 = 0;
        bool posi = 1;
        for(int i = 1; i < see.size() && posi;++i){
            if(see[i] == see[i-1] && see[i] == '1') see1 = 1;
            else if(see[i] == see[i-1] && see1) posi = 0;
        }
        if(posi) puts("YES");
        else puts("NO");
    }
}
