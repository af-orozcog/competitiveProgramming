#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll top = 10000000000ll;

int main(){
    vector<ll> fibs;
    fibs.push_back(0);
    fibs.push_back(1);
    while(fibs.back() <= top)
        fibs.push_back(fibs[fibs.size()-1]+fibs[fibs.size()-2]);
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        int ind = lower_bound(fibs.begin(),fibs.end(),n) - fibs.begin();
        if(fibs[ind] == n)
            puts("IsFibo");
        else
            puts("IsNotFibo");
    }
    return 0;
}
