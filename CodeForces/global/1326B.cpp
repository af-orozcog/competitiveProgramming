#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n;
    cin >> n;
    int ma = 0;
    int ans[n];
    for(int i = 0; i < n;++i){
        int va; cin >> va;
        //cout << va << endl;
        ans[i] = va+ma;
        //cout << ans[i] << endl;
        if(ans[i] > ma) ma = ans[i];
    }
    for(int i = 0; i < n;++i)printf("%d ",ans[i]);
    puts("");
    return 0;
}
