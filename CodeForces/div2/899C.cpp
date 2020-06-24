#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fastSum(ll n){
    return (n*(n+1ll))>>1;
}

int main(){
    ll n;
    scanf(" %lld",&n);
    ll imp = fastSum(n);
    int dif = 0;
    vector<ll> ans;
    if(imp == 3){
        ++dif;
        ans.push_back(1);
    }
    else if(imp&1){
        ++dif;
        ans.push_back(1);
        ans.push_back(n);
        imp >>= 1;
        imp -= n;
        --n;
        while(imp > n){
            if(imp -n > 1){
                imp -= n;
                ans.push_back(n);
            }
            --n;
        }
        if(imp!=0)
            ans.push_back(imp);
    }
    else{
        ans.push_back(n);
        imp >>= 1;
        imp -= n;
        --n;
        while(imp > n){
            if(imp -n > 1){
                imp -= n;
                ans.push_back(n);
            }
            --n;
        }
        if(imp!=0)
            ans.push_back(imp);
    }
    printf("%d\n",dif);
    printf("%d ",(int)ans.size());
    for(auto va:ans) printf("%d ",va);
    puts("");
    return 0;
}
