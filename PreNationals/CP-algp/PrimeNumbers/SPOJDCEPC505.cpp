#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll upTo = 1000700;
vector<ll> vals;
vector<ll> posi(upTo,1);

void init(){
    posi[1] = 3;;
    for(ll i = 2; i < upTo;++i)
        if(posi[i] == 1){
            posi[i] = i;
            for(ll j = i*2; j < upTo;j+=i){
                if(posi[j] == 1)
                    posi[j] = i;
            }
        }
    for(ll i = 2; i < upTo;++i){
        if(posi[(i/posi[i])] == (i/posi[i]) && posi[(i/posi[i])] != posi[i])
            vals.push_back(i);
    }
}


int main(){
    init();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        printf("%lld\n",vals[n-1]);
    }
    return 0;
}
