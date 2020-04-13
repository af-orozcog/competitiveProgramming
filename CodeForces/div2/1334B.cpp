#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,x;
        scanf(" %lld %lld",&n,&x);
        vector<ll> big,smal;
        for(ll i = 0; i < n;++i){
            int va; scanf(" %lld",&va);
            if(va >= x) big.push_back(va);
            else smal.push_back(va);
        }
        sort(big.begin(),big.end());
        sort(smal.begin(),smal.end());
        reverse(smal.begin(),smal.end());
        ll sumB = 0;
        int ans = big.size();
        for(auto va: big) sumB += va;
        for(int i = 0; i < smal.size();++i){
            if((sumB + smal[i])/((ll)ans+1ll) >= x)
                sumB += smal[i],++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
