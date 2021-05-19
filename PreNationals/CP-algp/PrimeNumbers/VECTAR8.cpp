#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

bitset<1000001> posi;
vector<int> ans(1000001);

bool isValid(int num){
    bool valid = 1;
    int now = 0;
    for(int i = 1; num && valid;i*=10){
        if(num % 10 == 0) return false;
        now += (i*(num%10));
        valid = posi[now];
        num /= 10;
    }
    return valid;
}


void sett(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < 1000001;++i){
        if(posi[i]){
            for(ll j = i*i; j < 1000001; j+= i) posi[j] = 0;
            if(isValid(i)) ans[i] = 1;
        }
    }
    for(int i = 1; i < ans.size();++i) ans[i] += ans[i-1];
}


int main(){
    sett();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
