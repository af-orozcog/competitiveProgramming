#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sumInRange(int from, int to, ll sums[], int n){
    if(to == -1) return 0;
    if(from == n) return 0;
    ll ans = sums[to];
    if(from > 0) ans -= sums[from-1];
    return ans;
}

int main(){
    int n;
    scanf(" %d",&n);
    ll sums[n];
    ll a[n],b[n];
    for(int i = 0; i < n;++i) scanf(" %lld",&a[i]);
    for(int i = 0; i < n;++i) scanf(" %lld",&b[i]);
    for(int i = 0; i < n;++i){
        sums[i] = a[i]*b[i];
        if(i) sums[i] += sums[i-1];
    }

    ll ans = sums[n-1];
    for(int i = 0; i < n-1;++i){
        int l = i, r = i+1;
        ll temp = a[l]*b[r] + a[r]*b[l];
        while(l > -1 && r < n){
            ll see = sumInRange(0,l-1,sums,n) + temp + sumInRange(r+1,n-1,sums,n);
            ans = max(ans,see);
            --l,++r;
            if(l > -1 && r < n)
                temp += a[l]*b[r] + a[r]*b[l];
        }
        l = i-1,r = i+1;
        temp = a[i]*b[i];
        while(l > -1 && r < n){
            temp += a[l]*b[r] + a[r]*b[l];
            ll see = sumInRange(0,l-1,sums,n) + temp + sumInRange(r+1,n-1,sums,n);
            ans = max(ans,see);
            --l,++r;
        }
    }


    printf("%lld\n",ans);
    return 0;
}
