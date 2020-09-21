#include<stdio.h>
#define ll long long

int main(){
    int n;
    scanf(" %d",&n);
    int neg = 0, pos = 0, zero = 0;
    ll ans = 0;
    for(int i = 0; i < n;++i){
        int va;
        scanf(" %d",&va);
        if(va > 0){
            ++pos;
            ans += (ll)va;
            --ans;
        }
        else if(va < 0){
            ++neg;
            ans += (ll)abs(va);
            --ans;
        }
        else
            ++zero;
    }
    ans += (ll)zero;
    if(neg%2 == 1 && !zero)
        ans += 2ll;
    printf("%lld\n",ans);
    return 0;
}
