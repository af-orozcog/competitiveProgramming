#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll see[3];
        scanf(" %lld %lld %lld",&see[0],&see[1],&see[2]);
        sort(see,see+3);
        ll bigger = see[2]+see[0]+see[1]-1ll;
        printf("%lld\n",bigger);
    }
    return 0;
}
