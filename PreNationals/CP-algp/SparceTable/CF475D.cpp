#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    vector<unordered_map<int,ll>> important(n);
    unordered_map<int,ll> every;
    for(int i = 0; i < n;++i){
        int val;
        scanf(" %d",&val);
        ++important[i][val];
        if(i){
            for(auto va:important[i-1]){
                int add = __gcd(va.first,val);
                important[i][add] += (ll)va.second;
            }
        }
        for(auto va:important[i])
            every[va.first] += (ll)va.second;
    }
    int q;
    scanf(" %d",&q);
    while(q--){
        int x;
        scanf(" %d",&x);
        printf("%lld\n",every[x]);
    }
    return 0;
}
