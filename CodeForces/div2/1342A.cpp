#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll x,y;
        scanf(" %lld %lld",&x,&y);
        ll a,b;
        scanf(" %lld %lld",&a,&b);
        ll pos1 = abs(x)*a + abs(y)*a;
        ll pos2;
        ll pos3;
        if(x >= 0)
            pos2 = x*b + abs((y-x))*a;
        else
            pos2 = abs(x)*b + abs((y-x))*a;
        if(y >= 0)
            pos3 = y*b + abs((x-y))*a;
        else
            pos3 = abs(y)*b + abs((x-y))*a;
        printf("%lld\n",min(pos1,min(pos2,pos3)));
    }
    return 0;
}
