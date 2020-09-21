#include<stdio.h>
#define ll long long

int main(){
    int n;
    scanf(" %d",&n);
    ll ans = 1;
    --n;
    ll i = 0;
    while(n--){
        ans += 4ll;
        ans += (i<<2);
        ++i;
    }
    printf("%lld\n",ans);
    return 0;
}
