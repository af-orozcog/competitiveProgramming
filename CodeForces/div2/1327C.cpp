#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    int maX = 0,maY = 0;
    for(int i = 0; i < k;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        maX = max(maX,a-1),maY = max(maY,b-1);
    }
    for(int i = 0; i < k;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
    }
    string ans = "";
    for(int i = 0; i < maX;++i) ans += 'U';
    for(int j = 0; j < maY;++j) ans += 'L';
    char ar[] = {'D','U'};
    for(int i = 0,j = 0; i < m;++i){
        for(int j = 0; j < n-1;++j)
            ans += ar[i&1];
        ans += 'R';
    }
    ans.pop_back();
    cout << ans.size() << "\n" << ans << "\n";
    return 0;
}
