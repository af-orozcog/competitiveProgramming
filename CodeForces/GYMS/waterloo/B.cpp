#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000
using namespace std;
#define pb push_back

typedef long long T;
set<T> sq;
void ini(){
    for(ll i = 1; i*i < MAX;++i) sq.insert(i*i);
}

int main(){
    ini();
    T k, y;
    cin>>k;
    set<T> rta;
    for(int d = 1; d*d<=k; ++d){
        if(k%d) continue;
        T x = d+(k/d);
        if(!(x&1)){
            x>>=1;
            y = x-d;
            if(y && x)
                rta.insert(-x*x);
        }
        x = k/d - d;
        if(!(x&1)){
            x>>=1;
            y = d+x;
            if(x && y)
                rta.insert(x*x);
        }
    }
    for(auto va: sq){
        T look = k - va;
        if(sq.count(look)) rta.insert(-look);
    }
    cout << rta.size() << "\n";
    for(auto va: rta) cout << va<<" ";
    return 0;
}
