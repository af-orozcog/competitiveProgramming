#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;

ll divi(int n){
    ll ans = 1;
    while(n % 2 == 0){
        ans <<= 1;
        n >>= 1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int w,h,n;
        scanf(" %d %d %d",&w,&h,&n);
        if(divi(w)*divi(h) >= (ll)n){
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}