#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sqr(ll num){
    ll lo = 1,hi = num,ans;
    while(lo <= hi){
        ll mid = (lo+hi)>>1;
        if(mid*mid <= num)
            ans = mid,lo = mid +1ll;
        else
            hi = mid - 1ll;
    }
    return ans;
}

int coun(ll num){
    if(num == 1)return 0;
    int ans = 0;
    ll to = sqr(num);
    while((num&1) == 0)
        ++ans,num >>= 1;
    for(ll i = 3; i <= to && num != 1ll;i+=2){
        while(num % i == 0){
            ++ans;
            num /= i;
        }
    }
    if(num > 2)
        ++ans;
    return ans;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll x;int k;
        scanf(" %lld %d",&x,&k);
        int co = coun(x);
        if(co >= k)puts("1");
        else puts("0");
    }
    return 0;
}
