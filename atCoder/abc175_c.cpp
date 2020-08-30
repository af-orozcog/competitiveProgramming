#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll x,k,d;
    scanf(" %lld %lld %lld",&x,&k,&d);
    ll toOther = (x/d)+1ll;
    if(x < 0){
        if(toOther > k)
            printf("%lld\n",x + d*k);
        else{
            ll op1 = x + d*toOther;
            ll op2 = op1-d;
            if(abs(op1) < abs(op2)){
                if((k-toOther) % 2ll == 0ll)
                    printf("%lld\n",abs(op1));
                else
                    printf("%lld\n",abs(op2));
            }
            else{
                if((k-toOther+1ll) % 2ll == 0ll)
                    printf("%lld\n",abs(op2));
                else
                    printf("%lld\n",abs(op1));
            }
        }
    }
    else{
        if(toOther > k)
            printf("%lld\n",x - d*k);
        else{
            ll op1 = x - d*toOther;
            ll op2 = op1+d;
            if(abs(op1) < abs(op2)){
                if((k-toOther) % 2ll == 0ll)
                    printf("%lld\n",abs(op1));
                else
                    printf("%lld\n",abs(op2));
            }
            else{
                if((k-toOther+1ll) % 2ll == 0ll)
                    printf("%lld\n",abs(op2));
                else
                    printf("%lld\n",abs(op1));
            }
        }
    }
    return 0;
}
