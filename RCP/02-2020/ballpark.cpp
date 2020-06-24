#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll re;
    scanf(" %lld",&re);
    ll imp = 1;
    ll last;
    ll co = re;
    while(co){
        last = co % 10;
        imp *= 10;
        co /= 10;
    }
    imp /= 10;
    ll one = (last+1ll)*imp;
    ll two = (last)*imp;
    //cout << one << " " << two << "\n";
    if(abs(re-one) <= abs(re-two))
        printf("%lld\n",one);
    else
        printf("%lld\n",two);
    return 0;
}
