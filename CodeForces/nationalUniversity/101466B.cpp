#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    sort(nums,nums+n);
    ll ans = 1;
    ll last = 1;
    for(int i = n-1;i > -1;--i){
        ans += last * (ll)nums[i];
        last = (ll)nums[i]*last;
    }
    cout << ans << endl;
    return 0;
}
