#include<bits/stdc++.h>
#define ll long long

using namespace std;

pair<ll,ll> solve(ll a){
    pair<ll,ll> ans;
    ans.first = ans.second = 0;
    for(ll i = 1; i*i <= a;++i){
        if(a %i == 0){
            ans.second += i;
            ++ans.first;
            if(a/i != i) ans.second += (a/i),++ans.first;
        }
    }
    return ans;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b,k;
        scanf(" %d %d %d",&a,&b,&k);
        int from = a / k;
        if(a%k)++from;
        pair<ll,ll> ans;
        ans.first = ans.second = 0;
        for(int i = from*k;i <= b;i += k){
            pair<ll,ll> va = solve(i);
            ans.first += va.first; ans.second += va.second;
        }
        printf("%lld %lld\n",ans.first,ans.second);
    }
    return 0;
}
