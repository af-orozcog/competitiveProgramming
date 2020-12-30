#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll sums[1000000];
ll nums[1000000];

void values(int lo ,int ri, unordered_set<ll> &vals){
    if(lo > ri) return;
    ll val = sums[ri];
    if(lo)
        val -= sums[lo-1];
    vals.insert(val);
    ll imp = sums[ri]+sums[lo];
    if(ri) imp -= sums[ri-1];
    if(lo) imp -= sums[lo-1];
    imp >>=1;
    int mid = upper_bound(nums,nums+ri+1,imp)-nums;
    if(mid-1 == ri)return;
    values(lo,mid-1,vals);
    values(mid,ri,vals);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,q;
        scanf(" %d %d",&n,&q);
        for(int i = 0; i < n;++i)
            scanf(" %lld",&nums[i]);
        sort(nums,nums+n);
        for(int i = 0; i < n;++i){
            sums[i] = nums[i];
            if(i)
                sums[i] += sums[i-1];
        }
        unordered_set<ll> vals;
        values(0,n-1,vals);
        while(q--){
            ll va;
            scanf(" %lld",&va);
            if(vals.count(va))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
