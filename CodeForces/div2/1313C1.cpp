#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll toLeft(ll ar[], int n, ll he){
    ll ans = 0;
    for(int i = n; i > -1;--i)
        he = min(he,ar[i]),ans += he;
    return ans;
}
ll toRight(ll ar[], int n, int siz, ll he){
    ll ans = 0;
    for(int i = n; i < siz;++i)
        he = min(he,ar[i]), ans += he;
    return ans;
}

int main(){
    int n;
    scanf(" %d",&n);
    ll nums[n];
    for(int i = 0; i < n;++i) scanf(" %lld",&nums[i]);
    ll ans = 0,who;
    for(int i = 0; i < n;++i){
       ll va = nums[i]+toLeft(nums,i-1,nums[i])+toRight(nums,i+1,n,nums[i]);
        if(va > ans) ans = va,who = i;
    }
    ll he = nums[who];
    for(int i = who+1; i < n;++i)
        nums[i] = min(nums[i],nums[i-1]);
    for(int i = who-1; i > -1;--i)
        nums[i] = min(nums[i],nums[i+1]);
    for(int i = 0; i < n;++i)printf("%lld ",nums[i]);
    puts("");
    return 0;
}
