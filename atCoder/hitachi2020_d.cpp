#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    ll n,t;
    scanf(" %lld %lld",&n,&t);
    pi nums[n];
    for(int i = 0; i < n;++i){
        scanf(" %lld %lld",&nums[i].first,&nums[i].second);
    }
    sort(nums,nums+n);
    ll no = 1;
    int ans = 0;
    int i = 0;
    while(i < n && no <= t){
        no = no*nums[i].first + nums[i].second;
        if(no <= t) ++ans;
        ++no;
        ++i;
    }
    printf("%lld\n",ans);
}
