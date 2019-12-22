#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,q,k;
    scanf(" %d %d %d",&n,&q,&k);
    set<int> d1,d2;
    for(int i = 0; i < n;++i){
        int d,x;
        scanf(" %d %d",&d,&x);
        if(d == 1) d1.insert(x);
        else d2.insert(x);
    }
    vector<pair<ll,i>> queries(q);
    for(int i = 0; i < q;++i){
        ll va;scanf(" %lld",&va);
        queries[i] = {-va,i};
    }
    sort(queries.begin(),queries.end());
    ll ans = 0;
    vector<ll> show(q);
    ll time = 0;
    for(int i = 0; i < q;++i){
        ll to = queries[i].first;
        while(time < to){

        }
    }
}
