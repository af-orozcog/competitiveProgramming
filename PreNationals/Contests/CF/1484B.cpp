#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;


bool allEqual(ll nums[], ll n){
    for(int i = 1; i < n;++i)
        if(nums[i] != nums[i-1]) return 0;
    return 1;
}

bool up(ll nums[], ll n){
    for(int i = 2; i < n;++i)
        if(nums[i]-nums[i-1] != nums[i-1] - nums[i-2]) return 0;
    return 1;
}

bool check(ll nums[], ll n, ll m, ll c){
    if(nums[0] > m) return 0;
    for(int i = 1; i < n;++i){
        ll see = nums[i-1]+c;
        if(see >= m) see -= m;
        if(see != nums[i]) return 0;
    }
    return 1;
}

ll whatC(ll nums[], ll n){
    for(int i = 1; i < n;++i){
        if(nums[i] > nums[i-1]) return nums[i]-nums[i-1];
    }
    return -1;
}

ll whatM(ll nums[], ll n, ll c){
    for(int i = 1; i < n;++i){
        if(nums[i] < nums[i-1]) return nums[i-1]+c-nums[i];
    }
    return -1;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        ll nums[n];
        for(int i = 0;i < n;++i) scanf(" %lld",&nums[i]);

        if(allEqual(nums,n) || up(nums,n)){
            puts("0");
            continue;
        }
        ll c = whatC(nums,n);
        if(c == -1){
            puts("-1"); continue;
        }
        ll m = whatM(nums,n,c);
        if(check(nums,n,m,c))
            printf("%lld %lld\n",m,c);
        else puts("-1");
    }
    return 0;
}
