#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int  t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        int dif = abs(b-a);
        if(a == b) puts("0");
        else if(a > b){
            if(dif%2 == 0) puts("1");
            else puts("2");
        }
        else if(b > a){
            if(dif&1) puts("1");
            else puts("2");
        }
    }
    return 0;
}
