#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    for(int i = 0; i < 2*k;++i){
        int a,b;
        cin >> a >> b;
    }
    string ans = "";
    for(int i = 0; i < n-1;++i) ans += 'U';
    for(int i = 0; i < m-1;++i) ans += 'L';
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            if(i != 0 && j == 0) ans += 'D';
            else if(m > 1 && i % 2 == 1) ans += 'L';
            else if(m > 1) ans += 'R';
        }
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
    return 0;
}
