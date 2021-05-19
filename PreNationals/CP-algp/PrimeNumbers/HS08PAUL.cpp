#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

bitset<10000002> posi;
vector<int> ans(10000002,0);

void sett(){
    posi.set();
    posi[0] = posi[1] = 0;
    ll upTo = sqrt(10000002);
    for(ll i = 2; i <= upTo;++i){
        if(posi[i]){
            for(int j = i*i; j < 10000002LL; j+=i) posi[j] = 0;
        }
    }
    vector<int> temp;
    for(ll i = 1; i*i < 10000002LL;++i)
        temp.push_back((int)(i*i));
    for(ll j = 0; (ll)temp[0] + j*j*j*j < 10000002LL;++j){
        ll use = j*j*j*j;
        for(int i = 0; i < temp.size() && (ll)temp[i]+use < 10000002LL;++i){
            if(posi[temp[i]+use]) ans[temp[i]+use] = 1;
        }
    }
    for(int i = 1; i < 10000002LL;++i) ans[i] += ans[i-1];
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
