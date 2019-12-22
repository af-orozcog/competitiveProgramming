#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll lo = 0, hi = 1000000000, ans;
        while(lo <= hi){
            ll mid = (lo+hi)>>1;
            ll see = (mid*(mid+1))>>1;
            if(see + min(a,b) >= max(a,b)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        cout << ans << endl;
    }
    return 0;
}
