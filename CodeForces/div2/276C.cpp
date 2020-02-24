#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    int vals[n];
    for(int i = 0; i < n;++i) cin >> vals[i];
    sort(vals,vals+n);
    ll pos[n+5];memset(pos,0,sizeof(pos));
    while(l--){
        int a,b;
        cin >> a >> b;
        --a,--b;
        ++pos[a],--pos[b+1];
    }
    ll imp[n];
    ll acum = 0;
    for(int i = 0; i < n;++i) {imp[i] = pos[i]+acum; acum += pos[i];}
    sort(imp,imp+n);
    ll ans = 0;
    for(int i = n-1;i > -1;--i) ans += imp[i]*vals[i];
    cout << ans << "\n";
    return 0;
}
