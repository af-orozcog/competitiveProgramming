#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,s;
        scanf(" %lld %lld",&n,&s);
        ll ans = 0;
        ll last;
        scanf(" %lld",&last);
        for(int i = 0; i < s-1;++i){
            ll actual;
            scanf(" %lld",&actual);
            if(last >= actual){
                ll posi1 = (last-actual)+1, posi2 = (n-last-1)+actual;
                ans += min(posi1,posi2);
            }
            else{
                ll posi1 = (last+1)+(n-actual), posi2 = (actual-last)-1;
                ans += min(posi1,posi2);
            }
            last = actual;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
