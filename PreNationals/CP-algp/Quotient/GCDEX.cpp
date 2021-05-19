#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> phi;
vector<ll> ans;

void sett(){
    phi.resize(1000001,0);
    ans.resize(1000001,0);

    for(int i = 1; i < phi.size();++i) phi[i] = i - 1;
    phi[1] = 1;
    for(int i = 2; i < phi.size();++i){
        if(phi[i] == i-1){
            for(int j = i*2; j < phi.size();j+=i) phi[j] -= phi[j]/i;
        }
    }

    for(int i = 1; i < ans.size();++i){
        for(int j = i*2,k = 2; j < ans.size();j+=i,++k) ans[j] += i*phi[k];
    }
    for(int i = 1; i < ans.size();++i) ans[i] += ans[i-1];

}

int main(){
    sett();
    int n;
    while(scanf(" %d",&n) == 1 && n){
        printf("%lld\n",ans[n]);
    }
    return 0;
}

