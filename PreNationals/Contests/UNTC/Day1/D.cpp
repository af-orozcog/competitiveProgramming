#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        int seen[26];
        memset(seen,0,sizeof(seen));
        for(auto va:b)
            ++seen[va-'a'];
        int ans = 0;
        for(auto va:a){
            if(seen[va-'a'])
                --seen[va-'a'];
            else break;
            ++ans;
        }
        cout << ans << "\n";
    }
}
