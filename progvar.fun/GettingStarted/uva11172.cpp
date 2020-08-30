#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        if(a < b)
            puts("<");
        else if(a > b)
            puts(">");
        else
            puts("=");
    }
    return 0;
}
