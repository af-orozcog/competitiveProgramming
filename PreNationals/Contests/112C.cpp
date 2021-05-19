#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    cin.tie(0);
    ll n,x,y;
    cin >> n >> x >> y;
    if(y < n || (y == n && y < x)){
        puts("-1");
        return 0;
    }
    ll left = y - n;
    ll imp = left + (ll)1;
    if(imp*imp + n - 1 < x){
        puts("-1");
        return 0;
    }
    cout << imp << "\n";
    for(int i = 0; i < n-1;++i) cout << 1 << "\n";
    return 0;
}
