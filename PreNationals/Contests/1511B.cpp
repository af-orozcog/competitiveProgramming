#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int countDigits(ll val){
    return to_string(val).size();
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ll ans3 = 2;
        while(countDigits(ans3) != c)
            ans3 <<=1;
        ll ans2 = ans3;
        while(countDigits(ans2) != b)
            ans2 *= (ll)3;
        ll ans1 = ans3;
        while(countDigits(ans1) != a)
            ans1 *= (ll)5;
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
