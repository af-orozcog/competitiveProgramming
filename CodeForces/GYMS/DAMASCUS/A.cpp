#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll R,r;
        scanf(" %lld %lld",&R,&r);
        if(R*R > ((r*r)<<1))
            puts("1");
        else
            puts("2");
    }
    return 0;
}
