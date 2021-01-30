#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n;
    scanf(" %d",&n);
    ll nums[n];
    ll check = 0;
    for(int i = 0; i < n;++i){
        ll va1,va2;
        scanf(" %lld %lld",&va1,&va2);
        check -= va1;
        nums[i] = va1+va1+va2;
    }
    sort(nums,nums+n);
    reverse(nums,nums+n);
    int i = 0;
    while(check <= 0){
        check += nums[i];
        ++i;
    }
    printf("%d\n",i);
    return 0;
}
