#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

bool comp(pi &a, pi &b){
    return a.second > b.second;
}

int main(){
    //freopen("icecream.in","r",stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        pi nums[n];
        for(int i = 0; i< n;++i)
            cin >> nums[i].first;
        for(int i = 0; i < n;++i)
            cin >> nums[i].second;
        sort(nums,nums+n);
        int where = k-1;
        for(int i = k;k < n && nums[i-1].first == nums[i].first;++i)
            ++where;
        pi nums2[where+1];
        for(int i = 0; i <= where;++i) nums2[i] = nums[i];
        sort(nums2,nums2+where+1,comp);
        ll ma = 0;
        ll sum = 0;
        for(int i = 0; i < k;++i){
            sum += nums2[i].second;
            ma = max(ma,nums2[i].first);
        }
        cout << ma << " " << sum << "\n";
    }
    return 0;
}
